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


typedef struct _node{
   uint32_t tagID;
   char cmd;
   struct _node *next;
} node;

void path_test(void);

void parse(char * str);

void get_currID(uint32_t * id, char * cmd);
void get_target(uint32_t * id, char * cmd);
void popLL(void);
node* find(uint32_t search_ID);
bool valid_recalc(node* currentPath, node* newPath);
void append_newPath(node* newPath);
void clear_after(node * start);


#endif /* PATH_H_ */
