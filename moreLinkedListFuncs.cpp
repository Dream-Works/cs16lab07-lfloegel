#include <cassert>
#include "linkedList.h"
#include "linkedListFuncs.h"

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the largest value.
// You may assume list has at least one element  
// If more than one element has largest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head

Node * pointerToMax(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.
  assert(list!=NULL);
  assert(list->head != NULL);

  Node *max = list->head;//set max to first Node 

  //initialization: set pointer to first node (will be the pointer that 
                  //moves down the linked list) 
  //condition: stop when pointer reaches NULL
  //increment: move on to next node for each loop
  for (Node *num = list->head; num != NULL; num = num->next) {
      //if the int num points to is greater than the int max points to
      //set num as new max
      if (num->data > max->data) {
        max = num;
      }

  }

  return max;

  // TODO: Insert code here to calculate and return
  //   value of pointer to max element (first one if ties.)
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return a pointer to node with the smallest value.  
// You may assume list has at least one element
// If more than one element has smallest value, 
//  break tie by returning a pointer to the one the occurs
//  earlier in the list, i.e. closer to the head
Node * pointerToMin(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);

  Node *min = list->head;

  for (Node *num = list->head; num !=NULL; num = num->next) {
      if (num->data < min->data) {
        min = num;
      }

  }

  return min;

  // TODO: Insert code here to calculate and return
  //   value of pointer to min element 
  //   (first one such value that occurs if there are ties.)
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the largest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int largestValue(LinkedList *list) {

  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);

  int max = 0;

  for (Node *num = list->head; num !=NULL; num = num->next) {
      if (num->data > max) {
        max = num->data;
      }
  }

  return max;

  // TODO: Insert code here to calculate and return
  //   largest value in list (which may not be unique).
}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the smallest value in the list.
// This value may be unique, or may occur more than once
// You may assume list has at least one element

int smallestValue(LinkedList *list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);
  assert(list->head != NULL);

  Node *min = list->head;
  int min1 = 0;

  for (Node *num = list->head; num != NULL; num = num->next) {
    if (num->data < min->data) {
      min1 = num->data;
    }
  }

  // TODO: Insert code here to calculate and return
  //   smallest value in list (which may not be unique).

  return min1; // STUB!  Replace this line with correct code

}

// list: ptr to a linked list of Node (each with int data, and Node * next)
// Return the sum of all values in the list.
// You may assume that list is not NULL
// However, the list may be empty (i.e. list->head may be NULL)
//  in which case your code should return 0.

int sum(LinkedList * list) {
  // Code may assume that these assertions are true;
  //  so does not need to do error checking for these conditions.

  assert(list!=NULL);

  int sum = 0;

   for (Node *num = list->head; num !=NULL; num = num->next) {
      sum = sum + num->data;

  }

  return sum; 

}

void deleteNodeIteratively(LinkedList *list, int value) {
//find target value 
//delete node with target value 

   assert(list!=NULL);
   assert(list->head != NULL);

   //Node *link = list->head;
   Node *before;
   Node *discard = list->head;

   //if need to delete first node, reassign before 
   //if (discard->data == value) {
    //before = list->head;
   // Node *after = list->head;
    //discard = discard->next;
    //free(after);
   //}



   //else {
   while ((discard->data != value) && (discard->next != NULL)) {
      before = discard;
      discard = discard->next;
    }
  
    //if discard is pointing to data, delete
    if (discard->data == value) {
    //delete node
      before->next = discard->next;
      delete discard;
    }
  
}


Node* deleteNodeRecursivelyHelper(Node* head, int value){

  //deletes specified nodes 
  //returns new head of linked list

  if (head == NULL) {
    return NULL;
  }
    
  if (head->data == value) {
      Node *move = head->next;
      delete head; 
      return deleteNodeRecursivelyHelper(move, value);
  } 

  else {
      head->next = deleteNodeRecursivelyHelper(head->next, value);
      return head;
  }
}


void deleteNodeRecursively(LinkedList* list, int value){

  assert(list!=NULL);
  assert(list->head != NULL);

   //Node *link = list->head;
  list->head = deleteNodeRecursivelyHelper(list->head, value);

}



void insertNodeToSortedList(LinkedList *list, int value) {


  assert(list!=NULL);
  //first find where the value fits
  //if current node data is smaller than value, then move to next node
  //else if value is less than a node data, insert it before it 

  Node* p = new Node;
  p->data = value;
  p->next = NULL;

  if(list->head == NULL) { //empty list
    list->head = p;
    list->tail = p;
  }

  else if (p->data < list->head->data) { //insert in first place
    p->next = list->head;
    list->head = p;
  }

  else {
    while((list->head->next != NULL) && (list->head->next->data < p->data)) {
      list->head = list->head->next;
    }
    p->next = list->head->next;
    list->head->next = p;
  }

}











































