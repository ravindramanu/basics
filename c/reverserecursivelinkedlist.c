#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist {
  int data;
  struct linkedlist * next;
} Node;

Node * head = NULL;

Node * createNode(int input){
    Node * headref = (Node *)(malloc(sizeof(Node)));
    headref->data = input;
    headref->next = NULL;
    return headref;
}

void peek(Node * headref){
  while (headref->next) {
    printf("Node data: %d\n", headref->data);
    headref = headref->next;
  }
  printf("Node data: %d\n", headref->data);
}

Node * reversenormal(Node * headref){
  Node * prevptr = NULL;
  Node * nextptr = NULL;
  Node * currptr = headref;

  while(currptr != NULL){
    nextptr = currptr->next;
    currptr->next = prevptr;
    prevptr = currptr;
    currptr = nextptr;
  }

  headref = prevptr;
  return headref;
}

// Unique case where we return a pointer the first element of the list
// We cannot use that to traverse the list because it will stop after one
// element. But we have updated the head so we use the head to peek.
Node * reverse(Node * nodeptr){
  if(nodeptr->next == NULL){
    head = nodeptr;
    return nodeptr;
  }
  Node * nodeptr1 = reverse(nodeptr->next);
  nodeptr1->next = nodeptr;
  nodeptr->next = NULL;
  return nodeptr;
}

int main(){
  head = createNode(1);
  head->next = createNode(2);
  head->next->next = createNode(3);
  head->next->next->next = createNode(4);

  peek(head);
  head = reversenormal(head);
  printf("Reversed.\n");
  peek(head);
  reverse(head);
  printf("Reversed.\n");
  peek(head);
  return 0;
}
