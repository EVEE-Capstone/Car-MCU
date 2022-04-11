/*
 * gpio.c
 *
 *  Created on: Dec 10, 2021
 *      Author: maxpettit
 */

#include "gpio.h"

void gpio_init(void){
  CMU_ClockEnable(cmuClock_GPIO, true);

  // Timer 0 Direction Motor
  GPIO_PinModeSet(gpioPortA, 0u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortA, 1u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortA, 2u, gpioModePushPull, 0);


  // Timer 2
  GPIO_PinModeSet(gpioPortA, 8u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortA, 9u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortA, 10u, gpioModePushPull, 0);

  // test Battery switches
  GPIO_PinModeSet(gpioPortC, 9u, gpioModePushPull, 0);  // charge en

  // NFC Reader
  GPIO_PinModeSet(gpioPortC, 0u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortC, 1u, gpioModeInput, 0);
  GPIO_PinModeSet(gpioPortB, 7u, gpioModePushPull, 0);
  GPIO_PinModeSet(gpioPortB, 8u, gpioModePushPull, 1);


  // max17043 FUEL GUAGE GPIO
  // scl = pd7 sda = pd6
  GPIO_PinModeSet(gpioPortD, 6u, gpioModeWiredAnd, 1);
  GPIO_PinModeSet(gpioPortD, 7u, gpioModeWiredAnd, 1);

  // BLE USART Pins
  GPIO_PinModeSet(gpioPortE, 13, gpioModePushPull, 1); // TX
  GPIO_PinModeSet(gpioPortE, 12, gpioModeInput, 1);    // RX


  // led toggle
  GPIO_PinModeSet(gpioPortC, 11u, gpioModePushPull, 0);
}


void charge_on(void){
  GPIO_PinOutSet(gpioPortC, 9u);  // sw charge
}


void charge_off(void){
  GPIO_PinOutClear(gpioPortC, 9u);  // sw charge
}
