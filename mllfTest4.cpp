#include "linkedListFuncs.h"
#include "moreLinkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {

  Node *p;
  int threeNums[3]={42,57,61};
  LinkedList *list = arrayToLinkedList(threeNums,3);
  ASSERT_EQUALS( "[42]->[57]->[61]->null", linkedListToString(list));
  //ASSERT_EQUALS(expectedm actual)

  cout << "Testing pointerToMin" << endl;

  //first case
  p = pointerToMin(list);
  ASSERT_TRUE(p!=NULL);
  if (p!=NULL) {
    ASSERT_TRUE(p->data==42);
    ASSERT_TRUE(p==list->head); //make sure p is pointing to same node as list->head
  }

  addIntToEndOfList(list,25);
  ASSERT_TRUE(list->head->data == 42);
  ASSERT_TRUE(list->tail->data == 25);
  //makes sure that the head and tails are pointing to the right numbers 
  //in the new linked list

  //second case with added 25
  p = pointerToMin(list);
  ASSERT_TRUE(p!=NULL);
  if (p!=NULL) {
    ASSERT_TRUE(p->data==25); //make sure min is 25
    ASSERT_TRUE(p->next==NULL); //make sure it is in the last node
    ASSERT_TRUE(p==list->tail); //since last node, make sure it equals tail
  }
  
  assertEquals( "[42]->[57]->[61]->[25]->null",
		linkedListToString(list),
		"list after adding 25");

  //adding 99 at end of linked list
  addIntToEndOfList(list,99);
  ASSERT_TRUE(list->head->data == 42); //make sure pointing to right head
  ASSERT_TRUE(list->tail->data == 99); //make sure pointing to right tail

  assertEquals( "[42]->[57]->[61]->[25]->[99]->null", 
		linkedListToString(list),
		"list after adding 99");

  p = pointerToMin(list);
  ASSERT_TRUE(p!=NULL);
  if (p!=NULL) {
    ASSERT_TRUE(p->data==25);
    ASSERT_TRUE(p->next==list->tail);
  }
  
  freeLinkedList(list); //clearing linked list
    
  
  return 0;
}

