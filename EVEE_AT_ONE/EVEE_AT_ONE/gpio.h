/*
 * gpio.h
 *
 *  Created on: Dec 10, 2021
 *      Author: maxpettit
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "em_cmu.h"
#include "em_gpio.h"
#include "em_assert.h"

#define TURN_PORT     gpioPortA
#define TURN_PIN0     0u
#define TURN_PIN1     1u

void gpio_init(void);
void charge_on(void);
void charge_off(void);

#endif /* GPIO_H_ */
