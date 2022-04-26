/*
 * gpio.c
 *
 *  Created on: Dec 10, 2021
 *      Author: maxpettit
 */

#include "gpio.h"

void gpio_init(void){
  CMU_ClockEnable(cmuClock_GPIO, true);

  // Timer 0
  GPIO_PinModeSet(gpioPortA, 0u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortA, 1u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortA, 2u, gpioModePushPull, 0);


  // Timer 2
  GPIO_PinModeSet(gpioPortA, 8u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortA, 9u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortA, 10u, gpioModePushPull, 0);


  // test LED
  GPIO_PinModeSet(gpioPortD, 7u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortD, 6u, gpioModePushPull, 0);

  GPIO_PinModeSet(gpioPortC, 0u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortC, 1u, gpioModeInput, 0);
  GPIO_PinModeSet(gpioPortB, 7u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortB, 8u, gpioModePushPull, 1);

}
