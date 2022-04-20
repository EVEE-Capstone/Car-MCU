/*
 * usart.h
 *
 *  Created on: Feb 17, 2022
 *      Author: maxpettit
 */

#ifndef SRC_USART_H_
#define SRC_USART_H_

#include "em_cmu.h"
#include "em_usart.h"
#include <stdio.h>
#include <string.h>


// USART2_RX #1 PA7
// USART2_TX #1 PA6

// BLE RX connects to SPI_MOSI
// BLE TX connects to SPI_MISO
#define BLE_USART   USART0      // USART0
#define BLE_STARTFRAME  '#'
#define BLE_SIGFRAME    '!'

typedef struct {
  uint32_t          loc;
  uint32_t          refFreq;
  uint32_t          baudrate;
  USART_Parity_TypeDef          parity;
  USART_Stopbits_TypeDef        stopbits;
  USART_Databits_TypeDef        databits;
  bool              msbf;
  bool              rx_en;
} USART_OPEN_STRUCT;


typedef enum{
  us_idle,
  us_transmit,
  us_wait_finish,
  us_receive_data
} BLE_UART_STATES;

typedef struct {
  BLE_UART_STATES    curr_state;
  USART_TypeDef        *usart;
  char                  string[320];
  uint32_t              string_len;
  uint32_t              counter;
  uint32_t              rxdataValid;
  volatile bool         sm_busy;      // If true state machine can't be restarted
} USART_STATE_MACHINE_STRUCT;


void ble_usart_open(void);
bool usart_tx_busy(USART_TypeDef *usart);
void ble_write(char* string);
bool ble_newData(void);
void at_write(char* string);
void ble_read(char * str);

#endif /* SRC_USART_H_ */
