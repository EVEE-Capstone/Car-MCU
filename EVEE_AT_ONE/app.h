/***************************************************************************//**
 * @file app.h
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

#ifndef APP_H
#define APP_H

#include "blink.h"
#include "em_gpio.h"
#include "timer.h"
#include "gpio.h"
#include "mfrc522.h"
#include "max17043.h"
#include "leuart.h"
#include "path.h"
#include "motor.h"

#include <stdio.h>

#define BAT_LOW_THRS    20
#define BAT_HI_THRS     50


/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void);

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void);
void app_send_battery(void);
void app_pwm_open(void);
void app_leuart_open(void);

#endif  // APP_H
