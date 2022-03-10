/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#include "app.h"


/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  blink_init();
  gpio_init();
  max17043_open();

  app_pwm_open();
  app_leaurt_open();
  timeout_open(TIMER1);
  mfrc522_open();
  mfrc522_config();
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  uint32_t i, upper, lower;
  uint32_t speed = 60;
  float percent;
  char read[80];
  char bat[12];
  uint32_t tag;

  if(get_timer_flag(TIMER0)){
      clear_timer_flag(TIMER0);
      i = max17043_soc();
      if(i){
          upper = i & 0xff00;
          lower = i & 0x00ff;
          percent = (upper >> 8) + (float)lower/256;
          percent = percent - 1;
      }

      sprintf(bat, "%d", percent*100);
      leuart_write(bat);
  }

  i = mfrc522_card();             // read nfc tag
  if(i != 0) timeout_reset();
  if(i == 0x8804c6d3){
      // start motor
      GPIO_PinOutSet(TURN_PORT, TURN_PIN0);
      GPIO_PinOutClear(TURN_PORT, TURN_PIN1);

      timer_dc_set(TIMER2, CH0, 0);
      timer_dc_set(TIMER2, CH1, speed);
  }
  if(i == 0x8804b6d3){
      // stop motor
      GPIO_PinOutClear(TURN_PORT, TURN_PIN0);
      GPIO_PinOutClear(TURN_PORT, TURN_PIN1);

      timer_dc_set(TIMER2, CH0, 0);
      timer_dc_set(TIMER2, CH1, 0);
  }

  if(leuart_newData()){
          leuart_read(read);

          tag = atoi(read);

  }
}

void app_pwm_open(void){
  APP_TIMER_PWM_TypeDef pwm_settings;

  pwm_settings.debugRun = true;
  pwm_settings.enable = false;
  pwm_settings.route_loc = TIMER2_LOC;
  pwm_settings.freq = 100;
  pwm_settings.duty0 = 50;
  pwm_settings.duty1 = 50;
  pwm_settings.duty2 = 50;
  pwm_settings.cc_enable = true;      // enables all 3 cc outputs per timer
  pwm_settings.cdti_enable = false;
  pwm_settings.prescale = 4;
  pwm_settings.of_enable = false;

  timer_pwm_open(TIMER2, &pwm_settings);


  timer_dc_set(TIMER2, CH0, 0);
  timer_dc_set(TIMER2, CH1, 0);
  timer_dc_set(TIMER2, CH2, 0);
  timer_start(TIMER2, true);



  pwm_settings.debugRun = true;
  pwm_settings.enable = false;
  pwm_settings.freq = 0;
  pwm_settings.duty0 = 50;
  pwm_settings.duty1 = 50;
  pwm_settings.duty2 = 50;
  pwm_settings.cc_enable = false;      // enables all 3 cc outputs per timer
  pwm_settings.cdti_enable = false;
  pwm_settings.prescale = 1024;
  pwm_settings.of_enable = true;
  pwm_settings.route_loc = TIMER0_LOC;
  timer_pwm_open(TIMER0, &pwm_settings);

  timer_start(TIMER0, true);
}

void app_leuart_open(void){
  LEUART_OPEN_STRUCT leuart_init;

  leuart_init.baudrate = 9600;
  leuart_init.databits = leuartDatabits8;
  leuart_init.enable = leuartEnable;
  leuart_init.parity = leuartNoParity;
  leuart_init.stopbits = leuartStopbits1;
  leuart_init.rxblocken = true;
  leuart_init.sfubrx = true;
  leuart_init.startframe_en = true;
  leuart_init.startframe = START_FRAME;
  leuart_init.sigframe_en = true;
  leuart_init.sigframe = SIG_FRAME;
  leuart_init.refFreq = 0;


  leuart_open(LEUART0, &leuart_init);
}
