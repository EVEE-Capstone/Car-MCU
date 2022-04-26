/*
 * i2c.c
 *
 *  Created on: Feb 10, 2022
 *      Author: maxpettit
 */


#include "i2c.h"

static I2C_STATE_MACHINE_STRUCT I2C0_STATE_MACHINE;

//***********************************************************************************
// Private functions
//***********************************************************************************
static void i2c_bus_reset(I2C_TypeDef *i2c);
static void ack_received(I2C_STATE_MACHINE_STRUCT *i2c_sm);
static void nack_received(I2C_STATE_MACHINE_STRUCT *i2c_sm);
static void rxdatav_received(I2C_STATE_MACHINE_STRUCT *i2c_sm);
static void mstop_received(I2C_STATE_MACHINE_STRUCT *i2c_sm);

//***********************************************************************************
// Global functions
//***********************************************************************************


bool i2c_is_busy(I2C_TypeDef *i2c){
  I2C_STATE_MACHINE_STRUCT * i2c_sm;
  if(i2c == I2C0) i2c_sm = &I2C0_STATE_MACHINE;
  return i2c_sm->sm_busy;
}

/***************************************************************************//**
 * @brief
 *  Driver to open an I2C peripheral
 *
 * @details
 *  This routine is a low level driver built to be very general. Is able to
 *  configure either I2C0 or I2C1. This function is called by device code to
 *  configure the bus for communication.
 *
 * @note
 *  Normally called once per peripheral/bus. The function i2c_start() is called
 *  to turn-on or the communication's state machine process.
 *
 * @param[in] i2c
 *  Pointer to I2C peripheral (here I2C0 or I2C1)
 *
 * @param[in] i2c_setup
 *  Is the STRUCT that the calling routine will use to set the parameters for
 *  I2C operation
 *
 ******************************************************************************/
void i2c_open(I2C_TypeDef *i2c, I2C_OPEN_STRUCT *i2c_setup){
  I2C_Init_TypeDef i2c_values;
  I2C_STATE_MACHINE_STRUCT * i2c_sm;
  if(i2c == I2C0) i2c_sm = &I2C0_STATE_MACHINE;

  // Enable Clock to appropriate I2C peripheral
  if(i2c == I2C0) CMU_ClockEnable(cmuClock_I2C0, true);

  // Test Clock Operation
  if ((i2c->IF & 0x01) == 0) {
    i2c->IFS = 0x01;
    EFM_ASSERT(i2c->IF & 0x01);
    i2c->IFC = 0x01;
  } else {
    i2c->IFC = 0x01;
    EFM_ASSERT(!(i2c->IF & 0x01));
  }


  // Initialize I2C Values for init function
  i2c_values.enable = i2c_setup->enable;
  i2c_values.clhr = i2c_setup->clhr;
  i2c_values.freq = i2c_setup->freq;
  i2c_values.master = i2c_setup->master;
  i2c_values.refFreq = i2c_setup->refFreq;
  I2C_Init(i2c, &i2c_values);

  // Route SCL and SDA signals
  i2c->ROUTE = i2c_setup->route_loc | I2C_ROUTE_SCLPEN | I2C_ROUTE_SDAPEN;

  i2c_bus_reset(i2c);

  /* Clear & Enable interrupts */
  // RXDATAV cleared when RX buffer is read
  i2c->IFC = 0xFFFFFFFF;
  i2c->CMD = I2C_CMD_CLEARTX;

  uint32_t intFlagEn = I2C_IEN_ACK;
  intFlagEn |= I2C_IEN_NACK;
  intFlagEn |= I2C_IEN_RXDATAV;
  intFlagEn |= I2C_IEN_MSTOP;

  i2c->IEN = intFlagEn;

  if(i2c == I2C0) NVIC_EnableIRQ(I2C0_IRQn);

  // Initialize busy to false
  i2c_sm->sm_busy = false;
}

/***************************************************************************//**
 * @brief
 *  Resets the I2C state machine of I2C peripheral and devices on bus
 *
 * @details
 *  A bus reset can be performed by setting the START and STOP bits in the
 *  I2Cn CMD register at the same time while the transmit buffer is empty.
 *  MSTOP bit in I2Cn IF register signals completion of reset.
 *
 * @note
 *  Private function.
 *
 * @param[in] i2c
 *  Pointer to I2C peripheral (here I2C0 or I2C1)
 *
 ******************************************************************************/
void i2c_bus_reset(I2C_TypeDef *i2c){
  i2c->CMD = I2C_CMD_ABORT;
  uint32_t save_state = i2c->IEN;
  i2c->IEN = 0;

  i2c->IFC = i2c->IF;
  i2c->CMD = I2C_CMD_CLEARTX;
  i2c->CMD = I2C_CMD_START | I2C_CMD_STOP;
  while(!(i2c->IF & I2C_IF_MSTOP));
  i2c->IFC = i2c->IF;

  i2c->IEN = save_state;
  i2c->CMD = I2C_CMD_ABORT;

}

/***************************************************************************//**
 * @brief
 *  Start a I2C state machine operation.
 *
 * @details
 *  Configures static struct I2C_STATE_MACHINE based off of function input. If I2C
 *  is already marked as busy we produce an error. Optionally reset peripheral/bus
 *  before starting operation. Sends device address with write or read bit.
 *
 * @note
 *  Additionally blocks sleep mode for I2C.
 *
 * @param[in] i2c
 *  Pointer to I2C peripheral (here I2C0 or I2C1)
 *
 * @param[in] device_addr
 *  Address of device to communicate with. Of type uint32_t
 *
 * @param[in] reg_addr
 *  Register address within external device to interact with. Of type uint32_t
 *
 * @param[in] data_bytes
 *  Number of data bytes sending or receiving. Helpful to keep track of long
 *  communication. Of type uint32_t
 *
 * @param[in] read
 *  Boolean saying whether to read or write first. True to read.
 *
 * @param[in] send_cmd
 *  Command to send to slave. Of type uint32_t
 *
 * @param[in] data
 *  Pointer to uint32_t. Either points to first data to be sent or location to
 *  save data received. Up to caller to protect overflow and provide valid data
 *
 * @param[in] i2c_reset
 *  Reset boolean. A value of True resets bus/peripheral before beginning operation.
 *
 * @param[in] callback
 *  Callback encoding defined by application. Of type uint32_t
 *
 ******************************************************************************/
void i2c_start(I2C_TypeDef *i2c, uint32_t device_addr, uint32_t reg_addr, uint32_t num_data,
    bool read, uint32_t *data, bool i2c_reset, uint32_t callback){

  I2C_STATE_MACHINE_STRUCT * i2c_sm;
  if(i2c == I2C0) i2c_sm = &I2C0_STATE_MACHINE;

  while(i2c_sm->sm_busy);
  EFM_ASSERT((i2c->STATE * _I2C_STATE_STATE_MASK) == I2C_STATE_STATE_IDLE);


  if(i2c_reset) i2c_bus_reset(i2c);   // If reset parameter is true execute a bus reset
                      // We do not need to save the value of the parameter
                      // (it's only used here) So we do not save it in struct
  i2c_sm->callback = callback;

  i2c_sm->curr_state = request_resouce;
  i2c_sm->i2c = i2c;
  i2c_sm->i2c_device_addr = device_addr;
  i2c_sm->i2c_register_addr = reg_addr;
  i2c_sm->num_data_bytes = num_data;
  i2c_sm->read = read;
  i2c_sm->counter = 0;
  i2c_sm->data = data;
  if(read) *(i2c_sm->data) = 0;
  i2c_sm->sm_busy = true;

  i2c->CMD = I2C_CMD_START;
  i2c->TXDATA = (i2c_sm->i2c_device_addr << 1);  // shift over one
}

/***************************************************************************//**
 * @brief
 *  Interrupt Service Routine for I2C0
 *
 * @details
 *  Clear the interrupt flag register. Check each possible interrupt and
 *  call unique interrupt function to progress through state machine.
 *
 * @note
 *  Assert the interrupt flag has been cleared except for RXDATAV whose interrupt
 *  is not cleared by the IFC register but by reading the data.
 *
 ******************************************************************************/
void I2C0_IRQHandler(void){
  uint32_t int_flag;
  int_flag = I2C0->IF & I2C0->IEN;
  I2C0->IFC = int_flag;

  if(int_flag & I2C_IF_ACK){
    EFM_ASSERT(!(I2C0->IF & I2C_IF_ACK));
    ack_received(&I2C0_STATE_MACHINE);
  }
  if(int_flag & I2C_IF_NACK){
    EFM_ASSERT(!(I2C0->IF & I2C_IF_NACK));
    nack_received(&I2C0_STATE_MACHINE);
  }
  if(int_flag & I2C_IF_RXDATAV){
    rxdatav_received(&I2C0_STATE_MACHINE);
  }
  if(int_flag & I2C_IF_MSTOP){
    EFM_ASSERT(!(I2C0->IF & I2C_IF_MSTOP));
    mstop_received(&I2C0_STATE_MACHINE);
  }
}


static void ack_received(I2C_STATE_MACHINE_STRUCT *i2c_sm){
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();

  switch(i2c_sm->curr_state){
  case request_resouce:
    i2c_sm->curr_state = reg_addr;
    i2c_sm->i2c->TXDATA = i2c_sm->i2c_register_addr;
    break;
  case reg_addr:
    if(i2c_sm->read){
        i2c_sm->curr_state = slave_id;
        i2c_sm->i2c->CMD = I2C_CMD_START;   // repeated start
        i2c_sm->i2c->TXDATA = (i2c_sm->i2c_device_addr << 1 | 1);
    }else{
        i2c_sm->curr_state = write;
        i2c_sm->i2c->TXDATA = i2c_sm->data[i2c_sm->counter];    // TODO:update
        i2c_sm->counter++;
    }
    break;
  case slave_id:
    i2c_sm->curr_state = read;
    break;
  case write:
    if(i2c_sm->counter == i2c_sm->num_data_bytes){
        i2c_sm->curr_state = stop;
        i2c_sm->i2c->CMD = I2C_CMD_STOP;
    }
    else{
      i2c_sm->i2c->TXDATA = i2c_sm->data[i2c_sm->counter];
      i2c_sm->counter++;
    }
    break;
  case read:
  case stop:
  default:
    EFM_ASSERT(false);
    break;
  }
  CORE_EXIT_CRITICAL();
}

static void nack_received(I2C_STATE_MACHINE_STRUCT *i2c_sm){
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();

  switch(i2c_sm->curr_state){
    case request_resouce:
    case reg_addr:
    case slave_id:
    case read:
    case write:
    case stop:
    default:
      EFM_ASSERT(false);
      break;
  }
  CORE_EXIT_CRITICAL();
}

static void rxdatav_received(I2C_STATE_MACHINE_STRUCT *i2c_sm){
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();

  switch(i2c_sm->curr_state){
    case read:
      *i2c_sm->data |= i2c_sm->i2c->RXDATA << (8 * (i2c_sm->num_data_bytes-1));
      i2c_sm->num_data_bytes--;
      i2c_sm->counter++;
      if(i2c_sm->num_data_bytes > 0){
          i2c_sm->i2c->CMD = I2C_CMD_ACK;
      }
      if(i2c_sm->num_data_bytes == 0){
          i2c_sm->curr_state = stop;
          i2c_sm->i2c->CMD = I2C_CMD_NACK;
          i2c_sm->i2c->CMD = I2C_CMD_STOP;
      }
      break;
    case request_resouce:
    case reg_addr:
    case slave_id:
    case write:
    case stop:
    default:
      EFM_ASSERT(false);
      break;
  }
  CORE_EXIT_CRITICAL();
}

static void mstop_received(I2C_STATE_MACHINE_STRUCT *i2c_sm){
  CORE_DECLARE_IRQ_STATE;
  CORE_ENTER_CRITICAL();

  switch(i2c_sm->curr_state){
    case stop:
      i2c_sm->sm_busy = false;
      break;
    case request_resouce:
    case reg_addr:
    case slave_id:
    case read:
    case write:
    default:
      EFM_ASSERT(false);
      break;
  }
  CORE_EXIT_CRITICAL();
}

