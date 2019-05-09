#include<stdio.h>

#define LISTSIZE 5

typedef struct linkedlistnode {
  unsigned int itemnumber;
  unsigned int value;
  struct linkedlistnode *nextelement;
} Node;

// View list function
int view(Node *head){
  while(head->nextelement != NULL){
    printf("Item Number: %d Value: %d\n", head->itemnumber, head->value);
    head= head->nextelement;
  }
  printf("Item Number: %d Value: %d\n", head->itemnumber, head->value);
  return 0;
}

// Top elment function
int top(Node *head){
  printf("The top element of the list is %d\n", head->value);
  return 0;
}

// Last element function
int last(Node *head){
  // Drawbac of the linked list data structure
  while(head->nextelement != NULL){
    head = head->nextelement;
  }
  printf("The last element of the list is %d\n", head->value);
  return 0;
}

int main() {
  // Create list in heap (There are other ways to do this. Just did this for convenience)
  Node list[LISTSIZE];
  int i=0;

  for (i = 0; i < (LISTSIZE - 1); i++) {
    list[i].itemnumber = i+1;
    list[i].value = i*10;
    list[i].nextelement = &list[i+1];
  }

  // Set tail
  list[i].itemnumber = i+1;
  list[i].value = i*10;
  list[i].nextelement = NULL;

  // Viewing a linked list
  view(list);

  // Top element of the list
  top(list);

  // Last element of the list
  last(list);

  return 0;
}