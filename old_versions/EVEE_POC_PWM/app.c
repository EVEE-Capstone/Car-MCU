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
  app_pwm_open();
  mfrc522_open();
  mfrc522_config();
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  uint32_t i;
  i = mfrc522_card(); // for testing
  if(i == 0x29ED965A){
      GPIO_PinOutSet(gpioPortC, 8u);
      GPIO_PinOutClear(gpioPortC, 9u);
  }
  else if(i == 0xE1AB731A){
      GPIO_PinOutSet(gpioPortC, 9u);
      GPIO_PinOutClear(gpioPortC, 8u);
  }
  else {
      GPIO_PinOutClear(gpioPortC, 8u);
      GPIO_PinOutClear(gpioPortC, 9u);
  }
}

void app_pwm_open(void){
  APP_TIMER_PWM_TypeDef pwm_settings;

  pwm_settings.debugRun = true;
  pwm_settings.enable = false;
  pwm_settings.route_loc = TIMER0_LOC;
  pwm_settings.freq = 100;
  pwm_settings.duty0 = 50;
  pwm_settings.duty1 = 50;
  pwm_settings.duty2 = 50;
  pwm_settings.cc_enable = true;      // enables all 3 cc outputs per timer
  pwm_settings.cdti_enable = false;

  timer_pwm_open(TIMER0, &pwm_settings);

  timer_start(TIMER0, true);
  timer_dc_set(TIMER0, CH0, 0);
  timer_dc_set(TIMER0, CH1, 25);
  timer_dc_set(TIMER0, CH2, 100);
}