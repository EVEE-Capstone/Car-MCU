/*
 * timer.c
 *
 *  Created on: Dec 8, 2021
 *      Author: maxpettit
 */


/*
 *  TIMER 0 == 4sec battery/BLE
 *  TIMER 1 == 4sec nfc timeout
 *  TIMER 2 == motor pwm control
 */

#include "timer.h"

static uint32_t TIMER0_FLAG;

void timeout_ctrl(void);

/***************************************************************************//**
 * @brief
 *   Example timer delay code from Keith Graham. Not used
 *
 * @details
 *   Used as an example only.
 *
 ******************************************************************************/
void timer_delay(uint32_t ms_delay){
  uint32_t timer_clk_freq = CMU_ClockFreqGet(cmuClock_HFPER);
  uint32_t delay_count = ms_delay *(timer_clk_freq/1000) / 1024;
  CMU_ClockEnable(cmuClock_TIMER1, true);
  TIMER_Init_TypeDef delay_counter_init = TIMER_INIT_DEFAULT;
    delay_counter_init.oneShot = true;
    delay_counter_init.enable = false;
    delay_counter_init.mode = timerModeDown;
    delay_counter_init.prescale = timerPrescale1024;
    delay_counter_init.debugRun = false;
  TIMER_Init(TIMER1, &delay_counter_init);
  TIMER0->CNT = delay_count;
  TIMER_Enable(TIMER1, true);
  while (TIMER1->CNT != 00);
  TIMER_Enable(TIMER1, false);
  CMU_ClockEnable(cmuClock_TIMER1, false);
}

/***************************************************************************//**
 * @brief
 *   Sets up specified timer in pwm mode
 *
 * @details
 *   Outputs currently either all on or all off.
 *
 ******************************************************************************/
void timer_pwm_open(TIMER_TypeDef *timer, APP_TIMER_PWM_TypeDef *settings){
  TIMER_Init_TypeDef timer_pwm_vals;
  TIMER_InitCC_TypeDef pwm_cc_vals;
  uint32_t timer_clk_freq = CMU_ClockFreqGet(cmuClock_HFPER);
  uint32_t top;
  double tmp_freq;

  if(timer == TIMER0){
      NVIC_EnableIRQ(TIMER0_IRQn);
      CMU_ClockEnable(cmuClock_TIMER0, true);
      TIMER0_FLAG = 0;
  }
  if(timer == TIMER1){
        NVIC_EnableIRQ(TIMER1_IRQn);
        CMU_ClockEnable(cmuClock_TIMER1, true);
    }
  if(timer == TIMER2){
        NVIC_EnableIRQ(TIMER2_IRQn);
        CMU_ClockEnable(cmuClock_TIMER2, true);
    }

  // in theory block sleep mode EM2 when starting a timer

  timer_pwm_vals.ati = false;
  timer_pwm_vals.clkSel = timerClkSelHFPerClk;
  timer_pwm_vals.count2x = false;
  timer_pwm_vals.debugRun = settings->debugRun;
  timer_pwm_vals.dmaClrAct = false;
  timer_pwm_vals.enable = false;
  timer_pwm_vals.fallAction = timerInputActionNone;
  timer_pwm_vals.mode = timerModeUp;
  timer_pwm_vals.oneShot = false;
  timer_pwm_vals.quadModeX4 = false;
  timer_pwm_vals.riseAction = timerInputActionNone;
  timer_pwm_vals.sync = false;

  if(settings->prescale == 4){
      timer_pwm_vals.prescale = timerPrescale4;
  }
  if(settings->prescale == 1024){
      timer_pwm_vals.prescale = timerPrescale1024;
  }

  // do not start timer yet
  TIMER_Init(timer, &timer_pwm_vals);

  if(settings->freq == 0) tmp_freq = 0.25;
  else tmp_freq = settings->freq;

  top = (timer_clk_freq/(settings->prescale*tmp_freq))-1;   // eq 18.4
  TIMER_TopSet(timer, top);


  // cmoa, cofoa, cufoa maybe unnecessary
  pwm_cc_vals.cmoa = timerOutputActionClear;
  pwm_cc_vals.cofoa = timerOutputActionSet;
  pwm_cc_vals.coist = false;
  pwm_cc_vals.cufoa = timerOutputActionNone;
  pwm_cc_vals.edge = timerEdgeNone;
  pwm_cc_vals.eventCtrl = 0;
  pwm_cc_vals.filter = false;
  pwm_cc_vals.mode = timerCCModePWM;
  pwm_cc_vals.outInvert = false;
  pwm_cc_vals.prsInput = false;
  pwm_cc_vals.prsOutput = 0;
  pwm_cc_vals.prsSel = 0;


  TIMER_InitCC(timer, CH0, &pwm_cc_vals);
  TIMER_InitCC(timer, CH1, &pwm_cc_vals);
  TIMER_InitCC(timer, CH2, &pwm_cc_vals);

  uint32_t dc0 = settings->duty0 * top / 100;
  uint32_t dc1 = settings->duty1 * top / 100;
  uint32_t dc2 = settings->duty2 * top / 100;
  if(settings->duty0 == 100) dc0 = top + 1;
  if(settings->duty1 == 100) dc1 = top + 1;
  if(settings->duty2 == 100) dc2 = top + 1;
  //get top duty / top (divide by 100 as well

  TIMER_CompareSet(timer, CH0, dc0);
  TIMER_CompareSet(timer, CH1, dc1);
  TIMER_CompareSet(timer, CH2, dc2);

  timer->ROUTE = (settings->route_loc
      | settings->cc_enable * (0x07 << 0)
      | settings->cdti_enable * (0x07 << 7)
      );

  if(settings->of_enable) timer->IEN = TIMER_IEN_OF;
}

/***************************************************************************//**
 * @brief
 *   Wrapper for starting and stopping timer
 *
 * @details
 *   Prepared for case of sleep mode blocking.
 *
 ******************************************************************************/
void timer_start(TIMER_TypeDef *timer, bool enable){
      TIMER_Enable(timer, enable);
}

/***************************************************************************//**
 * @brief
 *   Set the duty cycle of a timer channel. Duty Cycle integer between 0-100
 *
 * @details
 *   Can be used while timer is running.
 *
 ******************************************************************************/
void timer_dc_set(TIMER_TypeDef *timer, uint32_t ch, uint32_t duty){
  uint32_t dc;
  if(duty == 100) dc = timer->TOP + 1;
  else dc = duty * timer->TOP / 100;
  TIMER_CompareSet(timer, ch, dc);
}

void timeout_open(TIMER_TypeDef *timer){
  uint32_t timer_clk_freq = CMU_ClockFreqGet(cmuClock_HFPER);
  TIMER_Init_TypeDef timer_pwm_vals;
  uint32_t top;

  if(timer == TIMER1){
      NVIC_EnableIRQ(TIMER1_IRQn);
      CMU_ClockEnable(cmuClock_TIMER1, true);
  }

  timer_pwm_vals.ati = false;
  timer_pwm_vals.clkSel = timerClkSelHFPerClk;
  timer_pwm_vals.count2x = false;
  timer_pwm_vals.debugRun = false;
  timer_pwm_vals.dmaClrAct = false;
  timer_pwm_vals.enable = false;
  timer_pwm_vals.fallAction = timerInputActionNone;
  timer_pwm_vals.mode = timerModeUp;
  timer_pwm_vals.oneShot = true;
  timer_pwm_vals.prescale = timerPrescale1024;
  timer_pwm_vals.quadModeX4 = false;
  timer_pwm_vals.riseAction = timerInputActionNone;
  timer_pwm_vals.sync = false;

  // do not start timer yet
  TIMER_Init(timer, &timer_pwm_vals);

  top = (timer_clk_freq/(1024*TIMEOUT_FREQ))-1;   // eq 18.4
  TIMER_TopSet(timer, top);

  timer->IEN = TIMER_IEN_OF;

}


void TIMER0_IRQHandler(void){
  uint32_t int_flag;
  int_flag = TIMER0->IF & TIMER0->IEN;
  TIMER0->IFC = int_flag;

  if(int_flag & TIMER_IF_OF){
      TIMER0_FLAG = 1;
  }
}


void TIMER1_IRQHandler(void){
  uint32_t int_flag;
  int_flag = TIMER1->IF & TIMER1->IEN;
  TIMER1->IFC = int_flag;

  if(int_flag & TIMER_IF_OF){
      timeout_ctrl();
  }
}


void timeout_ctrl(void){
  GPIO_PinOutSet(gpioPortC, 11u);
}

void timeout_reset(void){
  if(!(TIMER1->STATUS & TIMER_STATUS_RUNNING)){
      timer_start(TIMER1, true);
  }
  else{
      TIMER1->CNT = 0;
  }
}

uint32_t get_timer_flag(TIMER_TypeDef *timer){
  if(timer == TIMER0) return TIMER0_FLAG;
  else return 0;
}

void clear_timer_flag(TIMER_TypeDef *timer){
  if(timer == TIMER0) TIMER0_FLAG = 0;
  else return;
}
