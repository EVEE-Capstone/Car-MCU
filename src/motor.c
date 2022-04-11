/*
 * motor.c
 *
 *  Created on: Feb 15, 2022
 *      Author: nsaidy
 */


#include "motor.h"


/***************************************************************************//**
 * STEERING
 *
 ******************************************************************************/
void left_turn(uint32_t speed) {
  GPIO_PinOutClear(TURN_PORT, TURN_PIN0);     // CH0 right
  GPIO_PinOutSet(TURN_PORT, TURN_PIN1);       // CH1 left

  // drive rear motors
  timer_dc_set(DRIVE_TIMER, CH0, 0);     // CH0 backward
  timer_dc_set(DRIVE_TIMER, CH1, speed); // CH1 forward
  }


void right_turn(uint32_t speed) {
  GPIO_PinOutSet(TURN_PORT, TURN_PIN0);     // CH0 right
  GPIO_PinOutClear(TURN_PORT, TURN_PIN1);   // CH1 left

  // drive rear motors
  timer_dc_set(DRIVE_TIMER, CH0, 0);     // CH0 backward
  timer_dc_set(DRIVE_TIMER, CH1, speed); // CH1 forward
  }

void straight(uint32_t speed) {
  GPIO_PinOutClear(TURN_PORT, TURN_PIN0);     // CH0 right
  GPIO_PinOutClear(TURN_PORT, TURN_PIN1);     // CH1 left

  // drive rear motors
  timer_dc_set(DRIVE_TIMER, CH0, 0);     // CH0 backward
  timer_dc_set(DRIVE_TIMER, CH1, speed); // CH1 forward
  }


/***************************************************************************//**
 * DRIVING
 *
 * 3 main points to be resolved
 *    Customizable speed
 *    Stopping
 *    Slow down around curves?
 *
 ******************************************************************************/
void move_forward(uint32_t speed) {
  // turn off front motor so axle straight
  GPIO_PinOutClear(TURN_PORT, TURN_PIN0);     // CH0 right
  GPIO_PinOutClear(TURN_PORT, TURN_PIN1);     // CH1 left

  // drive rear motors
  timer_dc_set(DRIVE_TIMER, CH0, 0);       // CH0 backward
  timer_dc_set(DRIVE_TIMER, CH1, speed);   // CH1 forward
}

void stop_motor(void) {
  // stop motors
  GPIO_PinOutClear(TURN_PORT, TURN_PIN0);     // CH0 right
  GPIO_PinOutClear(TURN_PORT, TURN_PIN1);     // CH1 left

  timer_dc_set(DRIVE_TIMER, CH0, 0);
  timer_dc_set(DRIVE_TIMER, CH1, 0);
}


/***************************************************************************//**
 * Control
 *
 ******************************************************************************/
void execute_cmd(char cmd){
  uint32_t speed = 50;

  switch(cmd){
    case 'L':
      // turn left code
      left_turn(speed);
      break;

    case 'R':
      // turn right code
      right_turn(speed);
      break;

    case 'Q':
      // execute charge code
      charge_on();
      stop_motor();
      break;

    case 'H':
      // execute halt code
      stop_motor();
      break;

    case 'S':
      // execute straight code
      straight(speed-20);
      break;

    case 'W':
      // execute straight code
      straight(speed-30);
      break;

    default:
      // probably just stop or drive slowly
      stop_motor();
      break;
  }
}
