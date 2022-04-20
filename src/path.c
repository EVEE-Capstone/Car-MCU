/*
 * path.c
 *
 *  Created on: Mar 10, 2022
 *      Author: maxpettit
 */

#include "path.h"


static node INST_ARR[INSTR_SIZE];
static int read_ptr;
static int write_ptr;

void push(uint32_t id, char cmd[3]);
static bool next_empty(void);

/***************************************************************************//**
 *   Initialize fifo circular buffer
 ******************************************************************************/
void initFIFO(void){
  read_ptr = 0;
  write_ptr = 0;
}

/***************************************************************************//**
 *   Parse input string into commands and ID, push to LL
 ******************************************************************************/
void parse(char * str){
  // might want to improve this with error detection
  clear_all();
  char * token;
  char s[2] = ",";
  int i = 0;
  uint32_t id;

  token = strtok(str, s);

  while( token != NULL ) {
      if(i % 2 == 1){
        push(id, token);       // needs to go with latter of id and cmd read
        i++;
      }
      else{
        id = atoi(token);
        i++;
      }
      token = strtok(NULL, s);
   }
}


/***************************************************************************//**
 *   Passes contents of head node
 ******************************************************************************/
void get_currID(uint32_t * id, char * cmd){
  if(is_empty()){
        *id = NO_ID;
        cmd[0] = 0;
        return;
    }
  *id = INST_ARR[read_ptr].tagID;
  cmd[0] = INST_ARR[read_ptr].cmd[0];
  cmd[1] = INST_ARR[read_ptr].cmd[1];
}


/***************************************************************************//**
 *   Passes contents of next node
 ******************************************************************************/
void get_target(uint32_t * id, char * cmd){
  if(is_empty()){
      *id = NO_ID;
      cmd[0] = 0;
      return;
  }
  if(next_empty()){
      *id = NO_ID;
      cmd[0] = 0;
      return;
  }

  *id = INST_ARR[(read_ptr + 1) % INSTR_SIZE].tagID;
  cmd[0] = INST_ARR[(read_ptr + 1) % INSTR_SIZE].cmd[0];
  cmd[1] = INST_ARR[(read_ptr + 1) % INSTR_SIZE].cmd[1];
}



/***************************************************************************//**
 *   Returns bool for arr is empty
 ******************************************************************************/
bool is_empty(void) {
  if(write_ptr == read_ptr) return true;
  return false;
}

/***************************************************************************//**
 *   Returns bool for if next spot is empty
 ******************************************************************************/
bool next_empty(void) {
  if(write_ptr == read_ptr + 1) return true;
  return false;
}

/***************************************************************************//**
 *   Returns bool for arr is full
 ******************************************************************************/
bool is_full(void) {
   if((write_ptr+1)%INSTR_SIZE == read_ptr) return true;
   return false;
}


/***************************************************************************//**
 *   Push a node
 ******************************************************************************/
void push(uint32_t id, char cmd[2]){
  if(is_full()) clear_all();

  INST_ARR[write_ptr].tagID = id;
  INST_ARR[write_ptr].cmd[0] = cmd[0];
  INST_ARR[write_ptr].cmd[1] = cmd[1];

  write_ptr = (write_ptr + 1) % INSTR_SIZE;

}


/***************************************************************************//**
 *   Delete current linked list
 ******************************************************************************/
void clear_all(void){
  read_ptr = 0;
  write_ptr = 0;
}

/***************************************************************************//**
 *   Pop head from array
 ******************************************************************************/
void popFIFO(void){
  read_ptr = (read_ptr + 1) % INSTR_SIZE;
}


/***************************************************************************//**
 *   Path test
 *   Given a sample string the car parses the path and drives it
 ******************************************************************************/
void path_test(void){
   unsigned int x;
   char c;
   char s[2];

   char tmp[16];
   char str[100];
   *str = 0;

   x = 0x8804B4D3;
   c = 'L';
   sprintf(tmp, "%d,%c,", x,c);
   strcat(str, tmp);

   x = 0x88048157;
   c = 'S';
   sprintf(tmp, "%d,%c,", x,c);
   strcat(str, tmp);

   x = 0x8804A6D0;
   c = 'L';
   sprintf(tmp, "%d,%c,", x,c);
   strcat(str, tmp);

   // 8dd3
   x = 0x88048DD3;
   s[0] = 'Y';
   s[1] = 'R';
   sprintf(tmp, "%d,%s,", x,s);
   strcat(str, tmp);

   // e0d0
   x = 0x8804E0D0;
   c = 'H';
   sprintf(tmp, "%d,%c,", x,c);
   strcat(str, tmp);

   parse(str);
//   clear_all();
}
