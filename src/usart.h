/*
 * usart.h
 *
 *  Created on: Dec 11, 2021
 *      Author: maxpettit
 */

#ifndef USART_H_
#define USART_H_

#include "em_cmu.h"
#include "em_usart.h"
#include "em_gpio.h"


typedef struct {
  uint32_t          loc;

  USART_Enable_TypeDef enable;
  uint32_t          refFreq;
  uint32_t          baudrate;
  USART_Databits_TypeDef  databits;
  bool              master;
  bool              msbf;
  USART_ClockMode_TypeDef   clockMode;
  bool              prsRxEnable;
  USART_PRS_Channel_t   prsRxCh;
  bool              autoTx;
  bool              autoCsEnable;
} SPI_OPEN_STRUCT;

typedef enum{
  spi_idle,
  spi_reg_addr,
  spi_transmit,
  spi_wait_finish,
  spi_close_process
} SPI_USART_STATES;


typedef struct {
  SPI_USART_STATES      curr_state;
  USART_TypeDef         *usart;
  uint32_t              wdata;
  uint32_t              addr;
  uint32_t              *rdata;
  uint32_t              num_bytes;
  uint32_t              rcounter;
  uint32_t              wcounter;
  bool                  read;
  volatile bool         sm_busy;      // If true state machine can't be restarted
  uint32_t              event;

  GPIO_Port_TypeDef          port;
  unsigned int               pin;
} SPI_STATE_MACHINE_STRUCT;


void spi_open(USART_TypeDef *usart, SPI_OPEN_STRUCT *spi_setup);
void spi_start(USART_TypeDef *usart, uint32_t addr, uint32_t write_data,
               uint32_t num_bytes, uint32_t *read_data, bool read,
               uint32_t event, GPIO_Port_TypeDef port, unsigned int pin);
bool spi_isbusy(USART_TypeDef *usart);

#endif /* USART_H_ */
