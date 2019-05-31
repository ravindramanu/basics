#include <stdio.h>
#include <stdlib.h>

// Buffer size is always almost known ahead of time
#define BUFFERSIZE 6

// Create structure for linked list item with one data item. Lets call it Node.
// These nodes are special in that they can point to the next node and the prev.
typedef struct linkedlistnode {
  int data;
  struct linkedlistnode * next;
} Node;

Node buffer[BUFFERSIZE];

Node * read, * write;

void createbuffer(){
  int i=0;

  for (i = 0; i < (BUFFERSIZE - 1); i++) {
    buffer[i].data = 0;
    buffer[i].next = &buffer[i+1];
  }

  // Set tail
  buffer[i].data = 0;
  buffer[i].next   = &buffer[0];

  write = &buffer[0];
  read = write;
}

/* Function to add
void writebuff(int inputdata){
  if (write == read) {
    printf("Buffer empty. Adding first element\n");
    head = (Node * )malloc(sizeof(Node));
    head->data = inputdata;
  }
  else if (read == write->next){
    printf("Buffer full\n");

  }
  else {

  }
  return;
}
*/

// Function to traverse through all the nodes and display them using the head
void peek(Node * headend){

  printf("List items are ordered as follows:\n");
  int i = 0;

  while (i < (BUFFERSIZE - 1)) {
    printf("Data: %d\n", headend->data);
    headend = headend->next;
    ++i;
  }
  // Lets not forget the tail
  printf("Data: %d\n", headend->data);
  printf("----------------------------------\n");
  return;
}

/* Function to traverse through all the nodes and display them using the tail
void peekreverse(Node * tailend){
  if(totalnodes != 0){
    printf("List items are ordered as follows:\n");
    while (tailend->prev != NULL) {
      printf("Data: %d\n", tailend->data);
      tailend = tailend->prev;
    }
    // Lets not forget the head
    printf("Data: %d\n", tailend->data);
    printf("Current stack size: %d\n", totalnodes);
    printf("----------------------------------\n");
    return;
  }
  printf("Stack is empty.\n");
  printf("----------------------------------\n");
  return;
}

// Funtion to pop the last value of the stack
void pop(int * inputdata){
  if(totalnodes != 0 && write->prev != NULL){
    Node * temppointer = write;
    * inputdata = temppointer->data;
    write = temppointer->prev;
    write->next=NULL;
    temppointer->prev = NULL;
    free(temppointer);
    --totalnodes;
    return;
  }else if (totalnodes!=0 && write->prev == NULL) {
    * inputdata = write->data;
    free(write);
    --totalnodes;
    return;
  }else {
    * inputdata = 0;
    printf("Stack is empty. Nothing to pop.\n");
    return;
  }
}
*/
// Main entry point
int main(void) {

  createbuffer();
  peek(write);

  return 0;
}
