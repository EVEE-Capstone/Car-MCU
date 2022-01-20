/*
 * mfrc522.c
 *
 *  Created on: Dec 11, 2021
 *      Author: maxpettit
 */


#include "mfrc522.h"

static uint32_t   read_data;

static void clear_collreg(void);
static uint32_t mfrc522_transceive(uint32_t fifo_data, uint32_t len, uint32_t txLastBits);


void mfrc522_open(void){
  SPI_OPEN_STRUCT mf_settings;
  mf_settings.autoCsEnable = false;
  mf_settings.autoTx = false;
  mf_settings.baudrate = MFRC522_BAUD;
  mf_settings.clockMode = usartClockMode0;
  mf_settings.databits = usartDatabits8;
  mf_settings.enable = usartEnable;
  mf_settings.master = true;
  mf_settings.msbf = true;
  mf_settings.prsRxCh = 0;
  mf_settings.prsRxEnable = false;
  mf_settings.refFreq = 0;
  mf_settings.loc = MFRC522_LOC;


  spi_open(MFRC522_USART, &mf_settings);
}


void mfrc522_write(uint32_t reg_address, uint32_t data, uint32_t num_bytes, uint32_t event){
  spi_start(MFRC522_USART, reg_address, data, num_bytes, 0, false, event, MFRC522_PORT, MFRC522_PIN);
}

void mfrc522_read(uint32_t reg_address, uint32_t num_bytes, uint32_t event){
  spi_start(MFRC522_USART, reg_address, 0, num_bytes, &read_data, true, event, MFRC522_PORT, MFRC522_PIN);
}


// starts communication with PICC
// 0x80 written to BitFramingReg to start transceive
uint32_t mfrc522_transceive(uint32_t fifo_data, uint32_t len, uint32_t txLastBits){
   mfrc522_write(MF_CommandReg, 0x00, 1, NO_CB);
   mfrc522_write(MF_ComIrqReg, 0x7F, 1, NO_CB);
   mfrc522_write(MF_FIFOLevelReg, 0x80, 1, NO_CB);
   mfrc522_write(MF_FIFODataReg, fifo_data, len, NO_CB);        // verify 0x26
   mfrc522_write(MF_BitFramingReg, txLastBits, 1, NO_CB);

   mfrc522_write(MF_CommandReg, 0x0C, 1, NO_CB);

   mfrc522_read(MF_BitFramingReg, 1, NO_CB);
   while(spi_isbusy(MFRC522_USART));
   mfrc522_write(MF_BitFramingReg, 0x80 | read_data, 1, NO_CB);

   // MF_waitIRQ
   while(1){
       mfrc522_read(MF_ComIrqReg, 1, NO_CB);
       while(spi_isbusy(MFRC522_USART));
       if(read_data & MF_waitIRQ) return 1;
       if(read_data & MF_timeoutIRQ){
           return 0;
       }
   }
}

uint32_t mfrc522_card(void){
  uint32_t val;
  uint32_t rv;

  mfrc522_write(MF_TxModeReg, 0x00, 1, NO_CB);
  mfrc522_write(MF_RxModeReg, 0x00, 1, NO_CB);
  mfrc522_write(MF_ModWidthReg, 0x26, 1, NO_CB);

  // collision clearing
  clear_collreg();
  rv = mfrc522_transceive(MF_CMD_REQA, 1, 0x07);

  if(rv == 0) return 0;


   mfrc522_read(MF_ErrorReg, 1, NO_CB);
   while(spi_isbusy(MFRC522_USART));
   if (read_data & 0x13) {   // BufferOvfl ParityErr ProtocolErr
       EFM_ASSERT(false);
   }

   clear_collreg();
   val = MF_CMD_SEL_CL1 << 8 | 0x20;
   rv = mfrc522_transceive(val, 2, 0);

   if(rv == 0) return 0;
   mfrc522_read(MF_FIFOLevelReg, 1, NO_CB);
   while(spi_isbusy(MFRC522_USART));

   val = read_data;

   mfrc522_read(MF_FIFODataReg, val-1, NO_CB);
   while(spi_isbusy(MFRC522_USART));
   val = read_data;

   return val;
}

void mfrc522_config(void){
  uint32_t val;
  mfrc522_write(MF_CommandReg, 0x0f, 1, NO_CB);     // soft reset

  mfrc522_write(MF_TxModeReg, 0x00, 1, NO_CB);
  mfrc522_write(MF_RxModeReg, 0x00, 1, NO_CB);
  mfrc522_write(MF_ModWidthReg, 0x26, 1, NO_CB);

  mfrc522_write(MF_TModeReg, 0x80, 1, NO_CB);
  mfrc522_write(MF_TPrescalerReg, 0xA9, 1, NO_CB);
  mfrc522_write(MF_TReloadRegH, 0x03, 1, NO_CB);
  mfrc522_write(MF_TReloadRegL, 0xE8, 1, NO_CB);

  mfrc522_write(MF_TxASKReg, 0x40, 1, NO_CB);
  mfrc522_write(MF_ModeReg, 0x3D, 1, NO_CB);


  mfrc522_read(MF_TxControlReg, 1, NO_CB);
  while(spi_isbusy(MFRC522_USART));
  val = read_data;
  if ((val & 0x03) != 0x03) {
      mfrc522_write(MF_TxControlReg, val | 0x03, 1, NO_CB);
  }

  return;
}


void clear_collreg(void){
  uint32_t val;
  mfrc522_read(MF_CollReg, 1, NO_CB);
  while(spi_isbusy(MFRC522_USART));
  val = read_data;
  mfrc522_write(MF_CollReg, val & ~(0x80) , 1, NO_CB);
}
