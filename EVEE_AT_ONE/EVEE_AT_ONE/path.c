/*
 * path.c
 *
 *  Created on: Mar 10, 2022
 *      Author: maxpettit
 */

#include "path.h"


static node *head = NULL;
static node *tail = NULL;


void push(uint32_t id, char instr);



//display the list
void printList(void) {
   node *ptr = head;

   //start from the beginning
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->tagID,ptr->cmd);
      ptr = ptr->next;
   }

}

//is list empty
bool is_empty(void) {
   return head == NULL;
}

void push(uint32_t id, char cmd){
  node *new = (struct node*) malloc(sizeof(node));

  new->cmd = cmd;
  new->tagID = id;
  new->next = NULL;

  if(!head) head = new;
  else tail->next = new;

  tail = new;
}


void pop(void){
  node * tmp;
  tmp = head;
  head = head->next;
  free(tmp);
}

void parse(char * str){

  char * token;
  char s[2] = ",";
  int i = 0;

  char * cmd;
  uint32_t id;


  token = strtok(str, s);

  while( token != NULL ) {

      if(i % 2 == 1){
        cmd = *token;
        push(id, cmd)
        i++;
      }
      else{
        id = atoi(token);
        i++;
      }
      token = strtok(NULL, s);
   }

}
