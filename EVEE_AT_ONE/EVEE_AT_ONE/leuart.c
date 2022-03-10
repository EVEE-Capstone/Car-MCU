/**
 * @file leuart.c
 * @author
 * @date
 * @brief Contains all the functions of the LEUART peripheral
 *
 */

//***********************************************************************************
// Include files
//***********************************************************************************

//** Standard Library includes
#include <string.h>

//** Silicon Labs include files
#include "em_gpio.h"
#include "em_cmu.h"

//** Developer/user include files
#include "leuart.h"

//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// private variables
//***********************************************************************************

static LEUART_STATE_MACHINE_STRUCT LEUART0_TX_STATE_MACHINE;
static LEUART_STATE_MACHINE_STRUCT LEUART0_RX_STATE_MACHINE;

/***************************************************************************//**
 * @brief LEUART driver
 * @details
 *  This module contains all the functions to support the driver's state
 *  machine to transmit a string of data across the LEUART bus.  There are
 *  additional functions to support the Test Driven Development test that
 *  is used to validate the basic set up of the LEUART peripheral.  The
 *  TDD test for this class assumes that the LEUART is connected to the HM-18
 *  BLE module.  These TDD support functions could be used for any TDD test
 *  to validate the correct setup of the LEUART.
 *
 ******************************************************************************/

//***********************************************************************************
// Private functions
//***********************************************************************************
static void txbl_recevied(LEUART_TypeDef *leuart);
static void txc_recevied(LEUART_TypeDef *leuart);
static void sigframe_recevied(LEUART_TypeDef *leuart);
static void rxdatav_recevied(LEUART_TypeDef *leuart);


//***********************************************************************************
// Global functions
//***********************************************************************************

/***************************************************************************//**
 * @brief
 *
 ******************************************************************************/

void leuart_open(LEUART_TypeDef *leuart, LEUART_OPEN_STRUCT *leuart_settings){
  LEUART_Init_TypeDef leuart_values;

  LEUART0_TX_STATE_MACHINE.rxdataValid = false;

    CMU_ClockEnable(cmuClock_LEUART0, true);
    leuart->STARTFRAME = true;
    while (leuart->SYNCBUSY);
    EFM_ASSERT(leuart->STARTFRAME & true);
    leuart->STARTFRAME = false;
    while (leuart->SYNCBUSY);

    leuart_values.enable = leuart_settings->enable;
    leuart_values.baudrate = leuart_settings->baudrate;
    leuart_values.databits = leuart_settings->databits;
    leuart_values.parity = leuart_settings->parity;
    leuart_values.stopbits = leuart_settings->stopbits;
    leuart_values.refFreq = leuart_settings->refFreq;

    leuart->CTRL = (LEUART_CTRL_SFUBRX * leuart_settings->sfubrx);
    LEUART_Init(leuart, &leuart_values);
    while (leuart->SYNCBUSY);

    leuart->STARTFRAME = leuart_settings->startframe;
    leuart->SIGFRAME = leuart_settings->sigframe;
    LEUART0->ROUTE = LEUART_ROUTE_LOCATION_LOC0 | LEUART_ROUTE_RXPEN | LEUART_ROUTE_TXPEN;

    NVIC_EnableIRQ(LEUART0_IRQn);

    leuart->CMD = LEUART_CMD_CLEARRX | LEUART_CMD_CLEARTX;
    while (leuart->SYNCBUSY);

    leuart->CMD = (leuart_settings->rxblocken * LEUART_CMD_RXBLOCKEN);
    while (leuart->SYNCBUSY);

    //LEUART_RX_STATE_MACHINE.curr_state = idle;
    LEUART_Enable(leuart, leuart_settings->enable);
    while(!(leuart->STATUS & (LEUART_STATUS_TXENS| LEUART_STATUS_RXENS)));
    EFM_ASSERT(leuart->STATUS & (LEUART_STATUS_TXENS | LEUART_STATUS_RXENS));
    leuart->IEN |= LEUART_IEN_RXDATAV | LEUART_IEN_SIGF;

}

/***************************************************************************//**
 * @brief
 *  Interrupt Service Routine for LEUART0.
 *
 * @details
 *  Clear the interrupt flag register. Check each possible interrupt and
 *  call unique interrupt function to progress through state machine.
 *
 * @note
 *  TXBL and RXDATAV cannot be cleared by the IFC.
 *
 ******************************************************************************/
void LEUART0_IRQHandler(void){
  uint32_t int_flag;
  int_flag = LEUART0->IF & LEUART0->IEN;
  LEUART0->IFC = int_flag;

  if(int_flag & LEUART_IF_TXBL){
    txbl_recevied(LEUART0);
  }
  if(int_flag & LEUART_IF_TXC){
    EFM_ASSERT(!(LEUART0->IF & LEUART_IF_TXC));
    txc_recevied(LEUART0);
  }
  if(int_flag & LEUART_IF_SIGF){
    EFM_ASSERT(!(LEUART0->IF & LEUART_IF_SIGF));
    sigframe_recevied(LEUART0);
  }
  if(int_flag & LEUART_IF_RXDATAV){
    rxdatav_recevied(LEUART0);
  }
}

/***************************************************************************//**
 * @brief
 *  Handles TXBL interrupt event. Progresses through LEUART state machine.
 *
 * @details
 *  Checks current state of LEUART state machine and performs TXBL response action
 *  if defined. Otherwise enters error.
 *
 * @note
 *  TXBL is only expected in transmit state and is disabled when the end of string
 *  is reached.
 *
 * @param[in] leuart
 *  Pointer to leuart peripheral
 *
 ******************************************************************************/
void txbl_recevied(LEUART_TypeDef *leuart){
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();

  switch(LEUART0_TX_STATE_MACHINE.curr_state){
  case transmit:
    leuart->TXDATA = LEUART0_TX_STATE_MACHINE.string[LEUART0_TX_STATE_MACHINE.counter];
    LEUART0_TX_STATE_MACHINE.counter = LEUART0_TX_STATE_MACHINE.counter + 1;
    if(LEUART0_TX_STATE_MACHINE.counter == LEUART0_TX_STATE_MACHINE.string_len){
      leuart->IEN &= ~LEUART_IEN_TXBL;
      LEUART0_TX_STATE_MACHINE.curr_state = wait_finish;
      leuart->IEN |= LEUART_IEN_TXC;
    }
    break;
  case wait_finish:
  case sig_frame:
  case idle:
  case receive_data:
  case close_uart:
  case configure:
  default:
    EFM_ASSERT(false);
    break;
  }
  CORE_EXIT_CRITICAL();
}


/***************************************************************************//**
 * @brief
 *  Handles TXC interrupt event. Progresses through LEUART state machine.
 *
 * @details
 *  Checks current state of LEUART state machine and performs TXC response action
 *  if defined. Otherwise enters error.
 *
 * @note
 *  TXC is only expected in wait_finish state and closes the uart operation if seen.
 *
 * @param[in] leuart
 *  Pointer to leuart peripheral
 *
 ******************************************************************************/
void txc_recevied(LEUART_TypeDef *leuart){
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();

  switch(LEUART0_TX_STATE_MACHINE.curr_state){
  case wait_finish:
    LEUART0_TX_STATE_MACHINE.curr_state = close_uart;
    leuart->IEN &= ~LEUART_IEN_TXC;
    LEUART0_TX_STATE_MACHINE.sm_busy = false;
    break;
  case close_uart:
  case idle:
  case sig_frame:
  case receive_data:
  case transmit:
  case configure:
  default:
    EFM_ASSERT(false);
    break;
  }
  CORE_EXIT_CRITICAL();
}

/***************************************************************************//**
 * @brief
 *  Handles SIGF received event. Progresses through LEUART state machine.
 *
 * @details
 *  Checks current state of LEAURT state machine and performs SIGF response action
 *  if defined. Sig frames only expected after a startframe.
 *
 * @note
 *  After SIG FRAME RXBLOCK is enabled until next start frame.
 *
 * @param[in] leaurt
 *  Pointer to LEUART peripheral
 *
 ******************************************************************************/
void sigframe_recevied(LEUART_TypeDef *leuart){
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();

  switch(LEUART0_RX_STATE_MACHINE.curr_state){
  case receive_data:
    // Append null character to received string
    LEUART0_RX_STATE_MACHINE.string[LEUART0_RX_STATE_MACHINE.counter] = 0;
    LEUART0_RX_STATE_MACHINE.curr_state = sig_frame;
    leuart->CMD = LEUART_CMD_RXBLOCKEN;
    LEUART0_RX_STATE_MACHINE.rxdataValid = true;
    while (leuart->SYNCBUSY);
    break;
  case wait_finish:
  case idle:
  case close_uart:
  case transmit:
  case sig_frame:
  case configure:
  default:
    EFM_ASSERT(false);
    break;
  }
  CORE_EXIT_CRITICAL();
}

/***************************************************************************//**
 * @brief
 *  Handles RXDATAV received event. Progresses through LEUART state machine.
 *
 * @details
 *  Checks current state of LEAURT state machine and performs RXDATAV response action
 *  if defined. RXDATAV is additionally triggered on sigframe interrupts.
 *
 * @note
 *  SIG FRAME is read and discarded so it does not linger in RXDATAV register and
 *  trigger additional interrupts.
 *
 * @param[in] leaurt
 *  Pointer to LEUART peripheral
 *
 ******************************************************************************/
void rxdatav_recevied(LEUART_TypeDef *leuart){
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();
  uint32_t rx;
  rx = leuart->RXDATA;

  switch(LEUART0_RX_STATE_MACHINE.curr_state){
  case idle:
    if(rx == leuart->STARTFRAME){
      LEUART0_RX_STATE_MACHINE.curr_state = receive_data;
      LEUART0_RX_STATE_MACHINE.counter = 0;
    }
    break;
  case receive_data:
    if(rx == leuart->STARTFRAME){
      LEUART0_RX_STATE_MACHINE.curr_state = receive_data;
      LEUART0_RX_STATE_MACHINE.counter = 0;
    }
    else{
      LEUART0_RX_STATE_MACHINE.string[LEUART0_RX_STATE_MACHINE.counter] = rx;
      LEUART0_RX_STATE_MACHINE.counter++;
    }
    break;
  case sig_frame:
    // Sig frame will cause a rxdata interrupt
    // Assert serves as error detection and clears rxdatav interrupt via read
    EFM_ASSERT(rx == leuart->SIGFRAME);
    LEUART0_RX_STATE_MACHINE.curr_state = idle;
    break;
  case wait_finish:
  case close_uart:
  case transmit:
  case configure:
  default:
    EFM_ASSERT(false);
    break;
  }
  CORE_EXIT_CRITICAL();
}

/***************************************************************************//**
 * @brief
 *
 ******************************************************************************/

void leuart_start(LEUART_TypeDef *leuart, char *string){
  while(leuart_tx_busy(leuart));

  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();
  LEUART0_TX_STATE_MACHINE.sm_busy = true;
  LEUART0_TX_STATE_MACHINE.string_len = strlen(string);
  strcpy(LEUART0_TX_STATE_MACHINE.string, string);
  LEUART0_TX_STATE_MACHINE.curr_state = configure;
  LEUART0_TX_STATE_MACHINE.counter = 0;
  LEUART0_TX_STATE_MACHINE.leuart = leuart;
  LEUART0_TX_STATE_MACHINE.curr_state = transmit;

  leuart->IEN |= LEUART_IEN_TXBL;
  CORE_EXIT_CRITICAL();
}


/***************************************************************************//**
 * @brief
 *
 ******************************************************************************/
bool leuart_tx_busy(LEUART_TypeDef *leuart){
  if(leuart == LEUART0)
    return LEUART0_TX_STATE_MACHINE.sm_busy;
  else return false;
}


/***************************************************************************//**
 * @brief
 *
 ******************************************************************************/
bool leuart_newData(void){
  return LEUART0_RX_STATE_MACHINE.rxdataValid;
}


/***************************************************************************//**
 * @brief
 *
 ******************************************************************************/
void leuart_read(char * str){
  strcpy(str, LEUART0_RX_STATE_MACHINE.string);
  LEUART0_RX_STATE_MACHINE.rxdataValid = false;
}


/***************************************************************************//**
 * @brief
 *
 ******************************************************************************/
void leuart_write(char * str){
  leuart_start(LEUART0, str);
}

