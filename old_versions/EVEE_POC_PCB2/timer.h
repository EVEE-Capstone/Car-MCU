/*
 * timer.h
 *
 *  Created on: Dec 8, 2021
 *      Author: maxpettit
 */

#ifndef TIMER_H_
#define TIMER_H_


#include "em_timer.h"
#include "em_cmu.h"


#define CH0     0
#define CH1     1
#define CH2     2

#define TIMER_EM      2     //EM2
#define TIMER0_LOC    TIMER_ROUTE_LOCATION_LOC0
#define TIMER2_LOC    TIMER_ROUTE_LOCATION_LOC0

typedef struct {
  bool      debugRun;           // True = keep LETIMER running will halted
  bool      enable;             // enable the LETIMER upon completion of open
  uint32_t  route_loc;
  uint32_t     freq;               // hz
  uint32_t     duty0;              // 0-100 % on
  uint32_t     duty1;              // 0-100 % on
  uint32_t     duty2;              // 0-100 % on
  bool      cc_enable;          // enable capture compare out 0-2
  bool      cdti_enable;        // enable cdti pins 0-2
} APP_TIMER_PWM_TypeDef;


void timer_delay(uint32_t ms_delay);
void timer_pwm_open(TIMER_TypeDef *timer, APP_TIMER_PWM_TypeDef *settings);
void timer_start(TIMER_TypeDef *timer, bool enable);
void timer_dc_set(TIMER_TypeDef *timer, uint32_t ch, uint32_t duty);


#endif /* TIMER_H_ */

