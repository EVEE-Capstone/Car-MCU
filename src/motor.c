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
//  timer_dc_set(DRIVE_TIMER, CH1, speed); // CH1 forward
  for(int i = 0; i < (int)speed; i++){
      timer_dc_set(DRIVE_TIMER, CH1, i); // CH1 forward
      for(int j = 0; j < 10; j++);
  }
}


void right_turn(uint32_t speed) {
  GPIO_PinOutSet(TURN_PORT, TURN_PIN0);     // CH0 right
  GPIO_PinOutClear(TURN_PORT, TURN_PIN1);   // CH1 left

  // drive rear motors
  timer_dc_set(DRIVE_TIMER, CH0, 0);     // CH0 backward
//  timer_dc_set(DRIVE_TIMER, CH1, speed); // CH1 forward
  for(int i = 0; i < (int)speed; i++){
      timer_dc_set(DRIVE_TIMER, CH1, i); // CH1 forward
      for(int j = 0; j < 150; j++);
  }
}

void straight(uint32_t speed) {
  GPIO_PinOutClear(TURN_PORT, TURN_PIN0);     // CH0 right
  GPIO_PinOutClear(TURN_PORT, TURN_PIN1);     // CH1 left

  // drive rear motors
  timer_dc_set(DRIVE_TIMER, CH0, 0);     // CH0 backward
//  timer_dc_set(DRIVE_TIMER, CH1, speed); // CH1 forward
  for(int i = 0; i < (int)speed; i++){
      timer_dc_set(DRIVE_TIMER, CH1, i); // CH1 forward
      for(int j = 0; j < 150; j++);
  }
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
void execute_cmd(char cmd[2]){
  uint32_t speed = 60;      // was 60
  char c = cmd[0];

  if(cmd[0] == SLOWCHAR){
      if(cmd[1] == 'S')
        speed = 52;         // was 50
      else speed = 55;      // was 50
      c = cmd[1];
  }

  switch(c){
    case 'L':
      // turn left code
      left_turn(speed+7);
      break;

    case 'R':
      // turn right code
      right_turn(speed+7);
      break;

    case 'O':     // Off
      stop_motor();
      break;

    case 'H':
      // execute halt code
      stop_motor();
      charge_on();
      break;

    case 'S':
      // execute straight code
      straight(speed-25);
      break;

    case 'W':     // Where am i
      straight(speed-25);
      break;

    case 'V':   // very slow
      straight(28);           // was 15
      break;

    case 'F':   // full forward force
      force();
      break;

    default:
      stop_motor();
      break;
  }
}

void reverse(void){
  uint32_t speed = 40;
  timer_dc_set(DRIVE_TIMER, CH0, speed);       // CH0 backward
  timer_dc_set(DRIVE_TIMER, CH1, 0);   // CH1 forward
}

void force(void){
  uint32_t speed = 65;
  // do we want wheels facing straight?
  GPIO_PinOutClear(TURN_PORT, TURN_PIN0);     // CH0 right
  GPIO_PinOutClear(TURN_PORT, TURN_PIN1);     // CH1 left

  timer_dc_set(DRIVE_TIMER, CH0, 0);       // CH0 backward
  timer_dc_set(DRIVE_TIMER, CH1, speed);   // CH1 forward
}

