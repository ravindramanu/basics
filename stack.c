#include <stdio.h>
#include <stdlib.h>

// Stack size is always almost known ahead of time
#define STACKSIZE 5
int totalnodes=0;

// Create structure for linked list item with one data item. Lets call it Node.
// These nodes are special in that they can point to the next node and the prev.
typedef struct linkedlistnode {
  int data;
  struct linkedlistnode * next;
  struct linkedlistnode * prev;
} Node;

Node * head, * tail;

// Function for push stack data
void push(int inputdata){
  if(totalnodes == 0){
    printf("Stack empty. Adding first element.\n");
    head = (Node * )malloc(sizeof(Node));
    head->data = inputdata;
    head->next = NULL; // Ensures untied node is the tail.
    head->prev = NULL; // Ensures untied node is the head.
    tail = head; // Match them so that we can access our stack from any point
    ++totalnodes; // Increment the total node tally
    return;
  }
  else if (totalnodes == STACKSIZE){
    printf("ERROR: Stack full. Lost traceability. Stack overflow.\n");
    return;
  }
  else {
    Node * temppointer = tail;
    tail = (Node * )malloc(sizeof(Node));
    tail->data = inputdata;
    tail->next = NULL; // Ensures untied node is the tail.
    temppointer->next = tail; // Set the old tail to point to the new tail
    tail->prev = temppointer; // Set the new tail to backtrack to the old tail
    ++totalnodes; // Increment the total node tally
    return;
  }
}

// Function to traverse through all the nodes and display them using the head
void displaynodes(Node * headend){
  if(totalnodes != 0){
    printf("List items are ordered as follows:\n");
    while (headend->next != NULL) {
      printf("Data: %d\n", headend->data);
      headend = headend->next;
    }
    // Lets not forget the tail
    printf("Data: %d\n", headend->data);
    printf("Current stack size: %d\n", totalnodes);
    printf("----------------------------------\n");
    return;
  }
  printf("Stack empty.\n");
  return;
}

// Function to traverse through all the nodes and display them using the tail
void displaytailnodes(Node * tailend){
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
  printf("Stack empty.\n");
  return;
}

// Funtion to pop the last value of the stack
void pop(int * inputdata){
  Node * temppointer = tail;
  * inputdata = temppointer->data;
  tail = temppointer->prev;
  tail->next=NULL;
  temppointer->prev = NULL;
  free(temppointer);
  --totalnodes;
  return;
}

// Main entry point
int main(void) {

  int data;

  push(15);
  displaynodes(head);

  push(64);
  displaynodes(head);

  push(12);
  displaynodes(head);

  push(931);
  displaynodes(head);

  push(932);
  displaynodes(head);

  pop(&data);
  displaytailnodes(tail);
  printf("Popped data is %d\n", data);

  pop(&data);
  displaytailnodes(tail);
  printf("Popped data is %d\n", data);
  return 0;
}
