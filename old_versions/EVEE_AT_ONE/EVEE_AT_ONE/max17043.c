/*
 * max17043.c
 *
 *  Created on: Feb 10, 2022
 *      Author: maxpettit
 */


// scl = pd7
// sda = pd6
// I2C_ROUTE_LOCATION_LOC1
// 1.3 to 0.6 low to high
// max 400kHz
// slave id = 0x36, accounting for shifting

#include "max17043.h"


static uint32_t max17043_read_result;
static uint32_t max17043_write_data;

//static void max17043_configure(void);

void max17043_open(void){
//  timer_delay(25);                          // TODO: need power on delay?

  I2C_OPEN_STRUCT max17043_i2c;
  max17043_i2c.clhr = i2cClockHLRAsymetric;
  max17043_i2c.freq = I2C_FREQ_FAST_MAX;
  max17043_i2c.enable = true;
  max17043_i2c.master = true;
  max17043_i2c.refFreq = 0;     // Set it to 0 if currently configured reference clock will be used
  max17043_i2c.route_loc = MAX17043_LOC;  // Defined in header file for compatibility with I2C0/I2C1

  i2c_open(MAX17043_I2C, &max17043_i2c);

//  si1133_configure();

}

void max17043_read(uint32_t si1133_read_cb, uint32_t reg_addr, uint32_t num_bytes){
  bool read = true;
  bool reset = true;

  i2c_start(MAX17043_I2C, MAX17043_ADDR, reg_addr, num_bytes, read, &max17043_read_result, reset, si1133_read_cb);
}

void max17043_write(uint32_t data, uint32_t si1133_write_cb, uint32_t reg_addr, uint32_t num_bytes){
  while(i2c_is_busy(MAX17043_I2C));
  bool read = false;
  bool reset = true;
  max17043_write_data = data;
  i2c_start(MAX17043_I2C, MAX17043_ADDR, reg_addr, num_bytes, read, &max17043_write_data, reset, si1133_write_cb);
}

uint32_t max17043_read_out(void){
  return max17043_read_result;
}


uint32_t max17043_soc(void){
  max17043_read(0, MAX17043_SOC_REG, 2);
  while(i2c_is_busy(MAX17043_I2C));

  return max17043_read_result;
}

//void max17043_configure(void){
//  uint32_t response0;
//  uint32_t new_resp;
//
//  // read response register
//  max17043_read(NULL_CB, SI1133_RESP0_REG, 1);
//  // wait for busy flag before reading result
//  while(i2c_is_busy(SI1133_I2C));
//  response0 = max17043_read_result & SI1133_CMMND_CTR_MASK;
//
//  // write white diode config
//  si1133_write(SI1133_WHITE_DATA, NULL_CB, SI1133_INPUT0_REG, 1);
//
//  // write param | adcconfig0
//  si1133_write(SI1133_PARAM_SET | SI1133_ADCCONFIG0_CMD, NULL_CB, SI1133_CMD_REG, 1);
//
//  // read has built in wait on busy flag
//  si1133_read(NULL_CB, SI1133_RESP0_REG, 1);
//  // wait for busy flag before reading result
//  while(i2c_is_busy(SI1133_I2C));
//  new_resp = si1133_read_result & SI1133_CMMND_CTR_MASK;
//  EFM_ASSERT((response0 + 1)%16 == new_resp);
//
//  // write to set channel 0 active
//  si1133_write(0b1, NULL_CB, SI1133_INPUT0_REG, 1);
//
//  // write has built in wait on busy flag
//  si1133_write(SI1133_PARAM_SET | SI1133_CHAN_LIST, NULL_CB, SI1133_CMD_REG, 1);
//
//  // read response register
//  si1133_read(NULL_CB, SI1133_RESP0_REG, 1);
//  // wait for busy flag before reading result
//  while(i2c_is_busy(SI1133_I2C));
//  new_resp = si1133_read_result & SI1133_CMMND_CTR_MASK;
//  EFM_ASSERT((response0 + 2)%16 == new_resp);
//}
//
//void si1133_force(void){
//  si1133_write(SI1133_FORCE_CMD, NULL_CB, SI1133_CMD_REG, 1);
//}
//
//
//// Not sure if professor wants us to read multiple bytes or not
//// But reading just SI1133_HOSTOUT1_REG works
//void si1133_request_sense(uint32_t callback){
//  si1133_read(callback, SI1133_HOSTOUT0_REG, 2);    //0x14
//}
//
