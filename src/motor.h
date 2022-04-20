/*
 * motor.h
 *
 *  Created on: Feb 15, 2022
 *      Author: nsaidy
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "timer.h"
#include "gpio.h"

/***************************************************************************//**
 * Defines
 ******************************************************************************/
#define LEFT 0
#define RIGHT 1
#define DRIVE_TIMER     TIMER2

#define SLOWCHAR 'Y'

/***************************************************************************//**
 * Turn Function
 ******************************************************************************/
void left_turn(uint32_t speed);
void right_turn(uint32_t speed);
void straight(uint32_t speed);
void move_forward(uint32_t speed);
void stop_motor(void);
void execute_cmd(char cmd[2]);
void reverse(void);
void force(void);

#endif /* MOTOR_H_ */

