/*
 * usart.c
 *
 *  Created on: Dec 11, 2021
 *      Author: maxpettit
 */


#include "usart.h"

static SPI_STATE_MACHINE_STRUCT SPI0_STATE_MACHINE;
static SPI_STATE_MACHINE_STRUCT SPI1_STATE_MACHINE;

static void txbl_recevied(SPI_STATE_MACHINE_STRUCT *sm);
static void txc_recevied(SPI_STATE_MACHINE_STRUCT *sm);
static void rxdatav_recevied(SPI_STATE_MACHINE_STRUCT *sm);

void spi_open(USART_TypeDef *usart, SPI_OPEN_STRUCT *spi_setup){
  if(usart == USART0){
      CMU_ClockEnable(cmuClock_USART0, true);
      NVIC_EnableIRQ(USART0_RX_IRQn);
      NVIC_EnableIRQ(USART0_TX_IRQn);
      SPI0_STATE_MACHINE.sm_busy = false;
  }
  if(usart == USART1){
      CMU_ClockEnable(cmuClock_USART1, true);
      NVIC_EnableIRQ(USART1_RX_IRQn);
      NVIC_EnableIRQ(USART1_TX_IRQn);
      SPI1_STATE_MACHINE.sm_busy = false;
  }

  if ((usart->IF & 0x01) == 0) {
    usart->IFS = 0x01;
    EFM_ASSERT(usart->IF & 0x01);
    usart->IFC = 0x01;
  } else {
      usart->IFC = 0x01;
    EFM_ASSERT(!(usart->IF & 0x01));
  }

  USART_Reset(usart);

  /* Initialize with default settings and then update fields according to application requirements. */
  USART_InitSync_TypeDef initSync = USART_INITSYNC_DEFAULT;

  /* Operate as SPI master */
  initSync.master = spi_setup->master;
  initSync.autoCsEnable = spi_setup->autoCsEnable;
  initSync.autoTx = spi_setup->autoTx;
  initSync.baudrate = spi_setup->baudrate;
  initSync.databits = spi_setup->databits;
  initSync.enable = usartDisable;
  initSync.msbf = spi_setup->msbf;
  initSync.prsRxCh = spi_setup->prsRxCh;
  initSync.prsRxEnable = spi_setup->prsRxEnable;
  initSync.refFreq = spi_setup->refFreq;
  initSync.clockMode = spi_setup->clockMode;  //usartClockMode;

  USART_InitSync(usart, &initSync);

  usart->CMD = USART_CMD_CLEARTX | USART_CMD_CLEARRX;


  usart->ROUTE = spi_setup->loc | USART_ROUTE_TXPEN
      | USART_ROUTE_RXPEN | USART_ROUTE_CLKPEN;


  USART_Enable(usart, spi_setup->enable);
}

void spi_start(USART_TypeDef *usart, uint32_t addr, uint32_t write_data,
               uint32_t num_bytes, uint32_t *read_data, bool read,
               uint32_t event, GPIO_Port_TypeDef port, unsigned int pin){

  SPI_STATE_MACHINE_STRUCT * sm_ptr;
  if(usart == USART0) sm_ptr =  &SPI0_STATE_MACHINE;
  if(usart == USART1) sm_ptr =  &SPI1_STATE_MACHINE;

  while(sm_ptr->sm_busy);

  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();
  sm_ptr->sm_busy = true;
  sm_ptr->num_bytes = num_bytes;
  sm_ptr->rdata = read_data;
  sm_ptr->addr = addr;
  sm_ptr->wdata = write_data;
  sm_ptr->usart = usart;
  sm_ptr->curr_state = spi_reg_addr;
  sm_ptr->rcounter = num_bytes;       //counts down for shifting reasons
  sm_ptr->wcounter = 0;
  sm_ptr->read = read;
  sm_ptr->event = event;
  sm_ptr->port = port;
  sm_ptr->pin = pin;

  *sm_ptr->rdata = 0;

  usart->CMD = USART_CMD_CLEARTX | USART_CMD_CLEARRX;

  GPIO_PinOutClear(sm_ptr->port, sm_ptr->pin);

  // In theory block EM2
  //    sleep_block_mode(USART_TX_EM);

  usart->IEN = USART_IEN_TXBL;
  if(read) usart->IEN |= USART_IEN_RXDATAV;
  else usart->IEN &= ~USART_IEN_RXDATAV;
  CORE_EXIT_CRITICAL();
}


bool spi_isbusy(USART_TypeDef *usart){
  if(usart == USART0) return SPI0_STATE_MACHINE.sm_busy;
  if(usart == USART1) return SPI1_STATE_MACHINE.sm_busy;
  return false;
}


void USART0_RX_IRQHandler(void){
  uint32_t int_flag;
  int_flag = USART0->IF & USART0->IEN;
  USART0->IFC = int_flag;

  if(int_flag & USART_IF_RXDATAV){
    rxdatav_recevied(&SPI0_STATE_MACHINE);
  }
}

void USART1_RX_IRQHandler(void){
  uint32_t int_flag;
  int_flag = USART1->IF & USART1->IEN;
  USART1->IFC = int_flag;

  if(int_flag & USART_IF_RXDATAV){
    rxdatav_recevied(&SPI1_STATE_MACHINE);
  }
}

void USART0_TX_IRQHandler(void){
  uint32_t int_flag;
  int_flag = USART0->IF & USART0->IEN;
  USART0->IFC = int_flag;

  if(int_flag & USART_IF_TXBL){
    txbl_recevied(&SPI0_STATE_MACHINE);
  }
  if(int_flag & USART_IF_TXC){
    EFM_ASSERT(!(USART0->IF & USART_IF_TXC));
    txc_recevied(&SPI0_STATE_MACHINE);
  }
}

void USART1_TX_IRQHandler(void){
  uint32_t int_flag;
  int_flag = USART1->IF & USART1->IEN;
  USART1->IFC = int_flag;

  if(int_flag & USART_IF_TXBL){
    txbl_recevied(&SPI1_STATE_MACHINE);
  }
  if(int_flag & USART_IF_TXC){
    EFM_ASSERT(!(USART1->IF & USART_IF_TXC));
    txc_recevied(&SPI1_STATE_MACHINE);
  }
}


void txbl_recevied(SPI_STATE_MACHINE_STRUCT *sm){
  switch(sm->curr_state){
  case spi_reg_addr:
    sm->curr_state = spi_transmit;
    sm->usart->TXDATA = (sm->read << 7)| (sm->addr << 1);
    break;

  case spi_transmit:
    if(sm->read){
        sm->wcounter++;
        if(sm->wcounter == sm->num_bytes){
            sm->usart->IEN &= ~USART_IEN_TXBL;
            sm->usart->TXDATA = 0;
        }
        if(sm->wcounter < sm->num_bytes) sm->usart->TXDATA = (sm->read << 7)| (sm->addr << 1);
    }
    else{
        sm->wcounter++;
        if(sm->wcounter == sm->num_bytes){
            sm->usart->IEN &= ~USART_IEN_TXBL;
            sm->curr_state = spi_wait_finish;
            sm->usart->IEN |= USART_IEN_TXC;

        }
        if(sm->wcounter <= sm->num_bytes){
            sm->usart->TXDATA = (sm->wdata >> (8*(sm->num_bytes - sm->wcounter))) & 0xFF;
        }
    }
    break;
  case spi_wait_finish:
  case spi_idle:
  case spi_close_process:
  default:
    EFM_ASSERT(false);
    break;
  }
}


void txc_recevied(SPI_STATE_MACHINE_STRUCT *sm){

  switch(sm->curr_state){
  case spi_wait_finish:
    sm->curr_state = spi_close_process;
    sm->usart->IEN &= ~USART_IEN_TXC;
    sm->sm_busy = false;
    GPIO_PinOutSet(sm->port, sm->pin);
//    sleep_unblock_mode(USART_TX_EM);
//    add_scheduled_event(SPI3_STATE_MACHINE.event);
    break;
  case spi_close_process:
  case spi_idle:
  case spi_transmit:
  default:
    EFM_ASSERT(false);
    break;
  }
}


void rxdatav_recevied(SPI_STATE_MACHINE_STRUCT *sm){
//  CORE_DECLARE_IRQ_STATE;
//  CORE_ENTER_CRITICAL();
  uint32_t rx;
  rx = sm->usart->RXDATA;

  switch(sm->curr_state){
  case spi_transmit:
    if(sm->rcounter == sm->num_bytes){
        sm->rcounter--;
        break;
    }
    *sm->rdata |= rx << (8*sm->rcounter);
    if(sm->rcounter == 0){
        sm->usart->IEN &= ~USART_IEN_RXDATAV;
        sm->usart->IEN &= ~USART_IEN_TXBL;
        sm->sm_busy = false;
        GPIO_PinOutSet(sm->port, sm->pin);
        sm->curr_state = spi_close_process;
//        sleep_unblock_mode(USART_TX_EM);
//        add_scheduled_event(SPI3_STATE_MACHINE.event);
        break;
    }

    sm->rcounter--;


    break;
  case spi_wait_finish:
  case spi_close_process:
  default:
    EFM_ASSERT(false);
    break;
  }

//  CORE_EXIT_CRITICAL();
}

