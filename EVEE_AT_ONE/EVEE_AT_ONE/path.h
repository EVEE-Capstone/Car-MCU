/*
 * path.h
 *
 *  Created on: Mar 10, 2022
 *      Author: maxpettit
 */

#ifndef PATH_H_
#define PATH_H_

#include <string.h>
#include "em_cmu.h"

typedef struct{
   uint32_t tagID;
   char cmd;
   node *next;
}node;

void printList();
bool LL_is_empty();


#endif /* PATH_H_ */
