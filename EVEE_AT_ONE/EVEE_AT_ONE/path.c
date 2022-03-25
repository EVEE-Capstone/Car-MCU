/*
 * path.c
 *
 *  Created on: Mar 10, 2022
 *      Author: maxpettit
 */

#include "path.h"

static node *head = NULL;
static node *tail = NULL;

void push(uint32_t id, char cmd);


/***************************************************************************//**
 *   Parse input string into commands and ID, push to LL
 ******************************************************************************/
void parse(char * str){

  char * token;
  char s[2] = ",";
  int i = 0;

  char cmd[2];
  uint32_t id;


  token = strtok(str, s);


  while( token != NULL ) {

      if(i % 2 == 1){
        *cmd = *token;
        push(id, cmd[0]);       // needs to go with latter of id and cmd read
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
  if(head){
      *id = head->tagID;
      *cmd = head->cmd;
  }
  else{
      *id = NO_ID;
      *cmd = 0;
  }
}


/***************************************************************************//**
 *   Passes contents of next node
 ******************************************************************************/
void get_target(uint32_t * id, char * cmd){
  if(!head){
      *id = NO_ID;
      *cmd = 0;
      return;
  }
  if(!(head->next)){
      *id = NO_ID;
      *cmd = 0;
      return;
  }

  *id = head->next->tagID;
  *cmd = head->next->cmd;
}



/***************************************************************************//**
 *   Returns bool for LL is empty
 ******************************************************************************/
bool is_empty(void) {
   return head == NULL;
}


/***************************************************************************//**
 *   Push a node
 ******************************************************************************/
void push(uint32_t id, char cmd){
  node *new = (node*) malloc(sizeof(node));

  new->cmd = cmd;
  new->tagID = id;
  new->next = NULL;

  if(!head) head = new;
  else tail->next = new;

  tail = new;
}


/***************************************************************************//**
 *   Delete after input node
 ******************************************************************************/
void clear_after(node * start){
  if(start == NULL) start = head;
  node *ptr = start->next;
  node *next;

   //start from the beginning
   while(ptr != NULL) {
      next = ptr->next;
      free(ptr);
      ptr = next;
   }
}

/***************************************************************************//**
 *   Pop head from LL
 ******************************************************************************/
void popLL(void){
  node * tmp;
  tmp = head;
  head = head->next;
  free(tmp);
}


//Function used to create a pointer at a wanted node
node* find(uint32_t search_ID){
  if(!head) return NULL; //Check to make sure that there is a linked list

  node * temp = head;
  while(temp!= NULL){
    if (temp->tagID == search_ID) return temp; //If the pointer is pointing at the correct node (node with tagID matching the one we are looking for), return that node
    temp = temp->next; //else continue down the list
  }

  return NULL; //Return NULL if we dont find the tagID in the list
}

bool valid_recalc(node* currentPath, node* newPath){
  if(currentPath->tagID != newPath->tagID || currentPath->cmd != newPath->cmd) return false; //If the cmd and the tagID at the front of both paths are not the same, return False
  else return true; //Else they are the same and return true
}

//Function to remove outdated list chunk and append new one
void append_newPath(node* newPath){
  if(!head) return; //Check to make sure that there is a linked list
  if(!valid_recalc(head, newPath)) return; //Make sure that the first nodes are the same, if they arent just return out without changing path

  node* delQue = find(newPath->tagID); //Create a pointer to the node (in the old path) that has the same tagID as the first node in the new path
  clear_after(delQue); //Delete all nodes that come after the delQue ptr

  delQue->next = newPath->next; //Append the rest of the path to the end of our current list (newPath->next because delQue should be the same as the first node in newPath)
}

/***************************************************************************//**
 *   Path test
 *   Given a sample string the car parses the path and drives it
 ******************************************************************************/
void path_test(void){
   unsigned int x;
   char c;

   char tmp[16];
   char str[100];
   *str = 0;

   x = 0x8804AC58;
   c = 'L';
   sprintf(tmp, "%d,%c,", x,c);
   strcat(str, tmp);

   x = 0x8804B458;
   c = 'R';
   sprintf(tmp, "%d,%c,", x,c);
   strcat(str, tmp);

   x = 0x88049CD1;
   c = 'H';
   sprintf(tmp, "%d,%c,", x,c);
   strcat(str, tmp);

   parse(str);
}
