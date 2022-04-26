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

static uint32_t LOW_BATTERY;
static uint32_t PREV_LOST;
static int ARRIVED;
static int SLOW_TO;
static int FORCE_TO;

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
//  blink_init();
  gpio_init();
  for(int i = 0; i < 800000; i ++);
  max17043_open();

  app_pwm_open();
  ble_usart_open();
  mfrc522_open();
  mfrc522_config();
  initFIFO();

  LOW_BATTERY = 0;
  PREV_LOST = 0;
  ARRIVED = 0;
  SLOW_TO = 0;
  FORCE_TO = 1;

  // For testing only
//  path_test();
//  ble_test();
  at_write("AT+CON0CEC80F08588");
  while(!get_timer_flag(TIMER0));
  clear_timer_flag(TIMER0);

  // Initial behavior
  app_send_battery();


  // ********
  charge_off();
  // ********

  execute_cmd("S");
  timeout_open(TIMER1);

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{

  uint32_t id;
  char read[300];
  char msg[40];
  *read = 0;

  uint32_t currID, targetID;
  char currCMD[2], targetCMD[2];


  // if TIMER0 has gone off we will get battery level and send it
  if(get_timer_flag(TIMER0)){
      clear_timer_flag(TIMER0);
      app_send_battery();
  }

  // if there is new data from model
  if(ble_newData()){
      ble_read(read);
      if(read[0] == 'q'){
          if(read[1] == 'c') charge_on();
          else charge_off();
      }
      else if(read[0] == '-' && read[1] == '2'){  // Path should start with '-2'
          parse(read);
          charge_off();
          get_currID(&currID, currCMD);
          execute_cmd(currCMD);
          ARRIVED = 0;
      }
  }

  // initially set to NO_ID and 0
  get_currID(&currID, currCMD);
  get_target(&targetID, targetCMD);

  // Read NFC tag from MFRC522 Module
  id = mfrc522_card();

  // if we read any tag reset timeout
  if(id != 0){
      timeout_reset();
      SLOW_TO = 0;
      FORCE_TO = 0;
  }

  // compare to path tags, target gets priority
  if(id == targetID){
      // execute the target command and pop from LL
      execute_cmd(targetCMD);
      if(targetCMD[0] == 'H' && !ARRIVED){
          ARRIVED = 1;

          if(targetCMD[1] != 'I'){
            // reverse to align, improve later
            for(int i  = 0; i < 10000; i++){
                 reverse();
                 if((i % 1000 == 900) && (mfrc522_card() == targetID)) break;
             }
            execute_cmd("H");
          }
          else execute_cmd("V");          // idle mode
          sprintf(msg, "I%d", (int)id);
          ble_write(msg);
          ble_write("AV");
      }
      else{
          popFIFO();
          sprintf(msg, "I%d", (int)id);
          ble_write(msg);
      }
  }
  // added to check if valid id first
  else if(id != 0 && id != currID && (id & (0x88040000)) == (0x88040000)) {
      // send alert back to model with id read
      // if we are newly lost
      if(id != PREV_LOST){
//          clear_all();  // clear list
          ARRIVED = 0;
          execute_cmd("W");     // TODO: test between W and O
          sprintf(msg, "r%d", (int)id);
          ble_write(msg);
          PREV_LOST = id;
      }
  }

  // if TIMER1 has gone off it has been 4 seconds since we saw a tag
    if(get_timer_flag(TIMER1)){
        clear_timer_flag(TIMER1);

        // If we timeout while in slow cmd, give it the non-slow version of cmd
        // if that still doesn't fix it alert
        if(currCMD[0] == SLOWCHAR && !SLOW_TO){
            SLOW_TO = 1;
            execute_cmd("F"); // &currCMD[1]
        }
        else if(ARRIVED){} // if we are at our destination don't alert to timeout
        else if(!FORCE_TO){
            FORCE_TO = 1;
            execute_cmd("F");
        }
        else{
            execute_cmd("O");   // stop car
            ble_write("TO");
        }
        timeout_reset();
    }
}


/***************************************************************************//**
 * Send battery to PG
 *
 ******************************************************************************/
void app_send_battery(void){
  uint32_t i, upper, lower;
  char bat[12];
  float percent;

  i = max17043_soc();
  if(i){
      upper = i & 0xff00;
      lower = i & 0x00ff;
      percent = (upper >> 8) + (float)lower/256;
      percent = percent - 1;
  }

  // If low battery, let model know
  // clear path if moving, do this only once per
//  if(!LOW_BATTERY && percent < BAT_LOW_THRS){
//      ble_write("LB");
//      LOW_BATTERY = 1;
//  }

//  if(LOW_BATTERY && percent >= BAT_HI_THRS){
//      LOW_BATTERY = 0;
//      ble_write("SC");
//  }

  sprintf(bat, "b%d", (int)(percent*100));
  ble_write(bat);
}


/***************************************************************************//**
 * Open PWMs for motor timer and 4 second timer
 *
 ******************************************************************************/
void app_pwm_open(void){
  APP_TIMER_PWM_TypeDef pwm_settings;

  // Setup TIMER 2 for motor use
  pwm_settings.debugRun = true;
  pwm_settings.enable = false;
  pwm_settings.route_loc = TIMER2_LOC;
  pwm_settings.freq = 100;
  pwm_settings.duty0 = 50;
  pwm_settings.duty1 = 50;
  pwm_settings.duty2 = 50;
  pwm_settings.cc_enable = true;      // enables all 3 cc outputs per timer
  pwm_settings.cdti_enable = false;
  pwm_settings.prescale = 4;
  pwm_settings.of_enable = false;

  timer_pwm_open(TIMER2, &pwm_settings);


  timer_dc_set(TIMER2, CH0, 0);
  timer_dc_set(TIMER2, CH1, 0);
  timer_dc_set(TIMER2, CH2, 0);
  timer_start(TIMER2, true);


  // Setup TIMER 0 for 4 second tag-read timeout
  pwm_settings.debugRun = true;
  pwm_settings.enable = false;
  pwm_settings.freq = 0;
  pwm_settings.duty0 = 50;
  pwm_settings.duty1 = 50;
  pwm_settings.duty2 = 50;
  pwm_settings.cc_enable = false;      // enables all 3 cc outputs per timer
  pwm_settings.cdti_enable = false;
  pwm_settings.prescale = 1024;
  pwm_settings.of_enable = true;
  pwm_settings.route_loc = TIMER0_LOC;
  timer_pwm_open(TIMER0, &pwm_settings);

  timer_start(TIMER0, true);
}

