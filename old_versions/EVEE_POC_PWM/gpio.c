/*
 * gpio.c
 *
 *  Created on: Dec 10, 2021
 *      Author: maxpettit
 */

#include "gpio.h"

void gpio_init(void){
  CMU_ClockEnable(cmuClock_GPIO, true);

  GPIO_PinModeSet(gpioPortA, 0u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortA, 1u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortA, 2u, gpioModePushPull, 0);

  // test LED
  GPIO_PinModeSet(gpioPortC, 9u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortC, 8u, gpioModePushPull, 0);

  GPIO_PinModeSet(gpioPortC, 0u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortC, 1u, gpioModeInput, 0);
  GPIO_PinModeSet(gpioPortB, 7u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortB, 8u, gpioModePushPull, 1);

}
