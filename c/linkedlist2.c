#include <stdio.h>
#include <stdlib.h>

// Create structure for linked list item with one data item. Lets call it Node.
typedef struct linkedlistnode {
  int data;
  struct linkedlistnode * next;
} Node;

// Function for creating a node with data. Returns a pointer to the node.
Node * createnode(int inputdata){
  Node * nodepointer = (Node * )malloc(sizeof(Node));
  nodepointer->data = inputdata;
  nodepointer->next = NULL; // Ensures untied node is the tail.
  return nodepointer;
}

/* Function for inserting a new node on top of the list and make that the new
 * head. The function accepts a reference to the pointer via a double pointer.
 * After creating a new node in the heap, the function makes the next pointer
 * of the new node to point to the old head. Once that is done, the old head
 * pointer is made to point to the new head. Now anytime te head is accessed
 * the new node will be accessed. The new node pointer is freed in the end of
 * function since it is no longer needed.
 */
void addhead(Node * * headreference, int inputdata){
  // For simplification:
  // *headreference is the head pointer pointing to the original head node.
  // newnode is the new head pointer that points to a new node in the heap.
  Node * newnode = (Node *)malloc(sizeof(Node));
  newnode->data = inputdata;
  // Make the new node next pointer to point the orignal head
  newnode->next = (* headreference);
  // Make the orignal head pointer to point to the new head
  (* headreference) = newnode;
  return;
}

// Function to traverse through all the nodes and display them
void displaynodes(Node * head){
  printf("List items are ordered as follows:\n");
  while (head->next != NULL) {
    printf("Data: %d\n", head->data);
    head = head->next;
  }
  // Lets not forget the tail
  printf("Data: %d\n", head->data);
  printf("----------------------------------\n");
  return;
}

// Funtion to traverse to the last item and append a node. Needs to defined
// after createnode since we are calling it. I dislike this dependency. But it
// beats having to unroll the contents of that function here.
void appendnode(Node * head, int appendinputdata){
  while (head->next != NULL) {
    head = head->next;
  }
  head->next = createnode(appendinputdata);
  return;
}

// Function to add a node after a specifc node in the List. First we search
// this node and then use some basic pointer wizardy to wrao it up.
void addafter(Node * head, int addafterselectdata, int addafterinputdata){
  // We will use this guy to do a little swaparoo
  Node * temppointer;
  // Traverse and find the element
  while (head->next != NULL) {
    if(head->data == addafterselectdata){
      temppointer = head->next;
      head->next = createnode(addafterinputdata);
      (head->next)->next = temppointer; // Classic swaparoo
      return;
    }
    head = head->next;
  }

  // Check tail. I really need a better way to encompass tail as well.
  if(head->data == addafterselectdata){
    temppointer = head->next;
    head->next = createnode(addafterinputdata);
    (head->next)->next = temppointer;
    return;
  }

  // We did not find anything at this point.
  printf("Selected node %d not found\n", addafterselectdata);
  return;
}

// Function to delete a node anywhere where certain specific data exists
void deletenodeat(Node * * headreference, int deletenodeatdata){
  // We want to leave the head alone so we will make a copy of it as a temp
  Node * temppointer;
  Node * trackerpointer;

  // First things first, a head can be deleted
  if ((* headreference)->data == deletenodeatdata) {
    // copy the pointer to the second element
    temppointer = (* headreference)->next;
    (* headreference)->next = NULL; // Cant have dangling pointers.
    (* headreference)->data = 0; // Lets set it to 0 before free it
    free(* headreference); // Now this heap space can be used for someting else
    (* headreference) = temppointer; // Reset our head to the new head
    return;
  }

  // Traverse and find the element we want to delete
  temppointer = (* headreference);
  while (temppointer->next != NULL) {
    if(temppointer->data == deletenodeatdata){
      trackerpointer->next = temppointer->next;
      temppointer->data = 0;
      temppointer->next = NULL;
      free(temppointer);
      return;
    }
    trackerpointer = temppointer;
    temppointer = temppointer->next;
  }

  if(temppointer->data == deletenodeatdata){
    trackerpointer->next = NULL;
    temppointer->data = 0;
    temppointer->next = NULL;
    free(temppointer);
    return;
  }

  printf("Key element not found.\n");
  return;
}

// Main entry point
int main(void) {

  printf("Creating the head node\n");
  Node * head = createnode(10);
  displaynodes(head);

  printf("Appending a node with data = 15\n");
  appendnode(head,15);
  displaynodes(head);

  printf("Adding a new head node with a data = 12\n");
  addhead(&head, 12);
  displaynodes(head);

  printf("Inserting a node in the list after element with data = 10\n");
  addafter(head, 15 , 22);
  displaynodes(head);

  printf("Checking if insert works at the end\n");
  addafter(head, 22 , 35);
  displaynodes(head);

  printf("Deleting head node\n");
  deletenodeat(&head, 12);
  displaynodes(head);

  printf("Deleting node with data 15\n");
  deletenodeat(&head, 15);
  displaynodes(head);

  printf("Appending a node with data = 64\n");
  appendnode(head,64);
  displaynodes(head);

  printf("Deleting node with data 64\n");
  deletenodeat(&head, 64);
  displaynodes(head);

  printf("Deleting non existant node\n");
  deletenodeat(&head, 250);
  displaynodes(head);

  return 0;
}
