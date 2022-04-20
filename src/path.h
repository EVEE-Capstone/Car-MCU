/*
 * path.h
 *
 *  Created on: Mar 10, 2022
 *      Author: maxpettit
 */

#ifndef PATH_H_
#define PATH_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "em_cmu.h"

// special IDs
#define NO_ID       1
#define INSTR_SIZE    64


typedef struct _node{
   uint32_t tagID;
   char cmd[2];
} node;

void path_test(void);
bool is_full(void);
bool is_empty(void);
void parse(char * str);

void get_currID(uint32_t * id, char * cmd);
void get_target(uint32_t * id, char * cmd);
void popFIFO(void);
void clear_all(void);
void initFIFO(void);


#endif /* PATH_H_ */
