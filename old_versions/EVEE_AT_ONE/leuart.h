//***********************************************************************************
// Include files
//***********************************************************************************
#ifndef LEUART_GUARD_H
#define LEUART_GUARD_H

#include "em_leuart.h"


//***********************************************************************************
// defined files
//***********************************************************************************

#define START_FRAME   '#'
#define SIG_FRAME    '!'

/***************************************************************************//**
 * @addtogroup leuart
 * @{
 ******************************************************************************/

typedef struct {
  uint32_t          baudrate;
  LEUART_Databits_TypeDef   databits;
  LEUART_Enable_TypeDef   enable;
  LEUART_Parity_TypeDef     parity;
  LEUART_Stopbits_TypeDef   stopbits;
  bool            rxblocken;
  bool            sfubrx;
  bool            startframe_en;
  char            startframe;
  bool            sigframe_en;
  char            sigframe;
  uint32_t        refFreq;
} LEUART_OPEN_STRUCT;


typedef enum{
  idle,
  configure,
  transmit,
  wait_finish,
  receive_data,
  sig_frame,
  close_uart
} HM10_LEUART_STATES;

typedef struct {
  HM10_LEUART_STATES    curr_state;
  LEUART_TypeDef        *leuart;
  char                  string[200];
  uint32_t              string_len;
  uint32_t              counter;
  volatile bool         sm_busy;      // If true state machine can't be restarted
  volatile bool    rxdataValid;
} LEUART_STATE_MACHINE_STRUCT;

/** @} (end addtogroup leuart) */

//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************
void leuart_open(LEUART_TypeDef *leuart, LEUART_OPEN_STRUCT *leuart_settings);
void LEUART0_IRQHandler(void);
void leuart_start(LEUART_TypeDef *leuart, char *string);
bool leuart_tx_busy(LEUART_TypeDef *leuart);
bool leuart_newData(void);
void leuart_read(char * str);
void leuart_write(char * str);


uint32_t leuart_status(LEUART_TypeDef *leuart);
void leuart_cmd_write(LEUART_TypeDef *leuart, uint32_t cmd_update);
void leuart_if_reset(LEUART_TypeDef *leuart);
void leuart_app_transmit_byte(LEUART_TypeDef *leuart, uint8_t data_out);
uint8_t leuart_app_receive_byte(LEUART_TypeDef *leuart);


#endif
