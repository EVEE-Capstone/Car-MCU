/*
 * max17043.h
 *
 *  Created on: Feb 10, 2022
 *      Author: maxpettit
 */

#ifndef MAX17043_H_
#define MAX17043_H_

#include "em_cmu.h"
#include "i2c.h"

#define   MAX17043_ADDR           0x36
#define   MAX17043_I2C            I2C0
#define   MAX17043_LOC            I2C_ROUTE_LOCATION_LOC1


#define   MAX17043_VCELL_REG      0x02
#define   MAX17043_SOC_REG        0x04
#define   MAX17043_MODE_REG       0x06
#define   MAX17043_VERSION_REG    0x08
#define   MAX17043_CONFIG_REG     0x0C

void max17043_open(void);
uint32_t max17043_soc(void);
uint32_t max17043_read_out(void);
void max17043_write(uint32_t data, uint32_t si1133_write_cb, uint32_t reg_addr, uint32_t num_bytes);
void max17043_read(uint32_t si1133_read_cb, uint32_t reg_addr, uint32_t num_bytes);

#endif /* MAX17043_H_ */
