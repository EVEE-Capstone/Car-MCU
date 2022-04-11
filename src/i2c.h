/*
 * i2c.h
 *
 *  Created on: Feb 10, 2022
 *      Author: maxpettit
 */

#ifndef I2C_H_
#define I2C_H_

#include "em_cmu.h"
#include "em_i2c.h"
#include "em_gpio.h"


typedef struct {
  bool      enable;     // enable i2c peripheral
  bool      master;     // Set to master (true) or slave mode
  uint32_t    refFreq;    // I2C reference clock assumed when configuring bus frequency setup.
  uint32_t    freq;     // (Max) I2C bus frequency to use.
  I2C_ClockHLR_TypeDef  clhr; // Clock low/high ratio control.
  uint32_t    route_loc;  // route to gpio port/pin
} I2C_OPEN_STRUCT;


typedef enum{
  request_resouce,
  reg_addr,
  slave_id,
  read,
  write,
  stop
} I2C_DEFINED_STATES;

typedef struct {
  I2C_DEFINED_STATES    curr_state;
  I2C_TypeDef       *i2c;
  uint32_t        i2c_device_addr;
  uint32_t        i2c_register_addr;
  uint32_t        *data;
  uint32_t        num_data_bytes;
  volatile bool          sm_busy;      // If true state machine can't be restarted
  bool          read;       // 1 for read, 0 for write
  uint32_t      counter;
  uint32_t      callback;
} I2C_STATE_MACHINE_STRUCT;


//***********************************************************************************
// function prototypes
//***********************************************************************************

void i2c_open(I2C_TypeDef *i2c, I2C_OPEN_STRUCT *i2c_setup);

void I2C0_IRQHandler(void);

void i2c_start(I2C_TypeDef *i2c, uint32_t device_addr, uint32_t reg_addr, uint32_t data_bytes,
    bool read, uint32_t *data, bool i2c_reset, uint32_t callback);

bool i2c_is_busy(I2C_TypeDef *i2c);



#endif /* I2C_H_ */
