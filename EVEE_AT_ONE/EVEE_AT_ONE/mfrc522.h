/*
 * mfrc522.h
 *
 *  Created on: Dec 11, 2021
 *      Author: maxpettit
 */

#ifndef MFRC522_H_
#define MFRC522_H_

#include "usart.h"

#define MFRC522_PORT    gpioPortB
#define MFRC522_PIN     8u
#define MFRC522_LOC     USART_ROUTE_LOCATION_LOC0
#define MFRC522_USART   USART1
#define MFRC522_BAUD    5000000       // max is min of (peripheral clock rate/2, 10Mbit)
#define NO_CB           0

#define MF_Status1Reg       0x07
#define MF_ComIrqReg        0x04
#define MF_FIFOLevelReg     0x0A
#define MF_ErrorReg         0x06
#define MF_FIFODataReg        0x09
#define MF_TxControlReg       0x14
#define MF_CommandReg       0x01
#define MF_ControlReg       0x0C
#define MF_BitFramingReg    0x0D
#define MF_TxModeReg        0x12
#define MF_RxModeReg        0x13
#define MF_ModeReg          0x11
#define MF_TxASKReg         0x15
#define MF_ModWidthReg      0x24
#define MF_CollReg          0x0E
#define MF_TModeReg         0x2A
#define MF_TPrescalerReg    0x2B
#define MF_TReloadRegH      0x2C
#define MF_TReloadRegL      0x2D

#define MF_waitIRQ          0x30
#define MF_timeoutIRQ       0x01
#define MF_CMD_SEL_CL1      0x93
#define MF_CMD_REQA         0x26


void mfrc522_open(void);
void mfrc522_config(void);
uint32_t mfrc522_card(void);
void mfrc522_write(uint32_t reg_address, uint32_t data, uint32_t num_bytes, uint32_t event);
void mfrc522_read(uint32_t reg_address, uint32_t num_bytes, uint32_t event);

#endif /* MFRC522_H_ */
