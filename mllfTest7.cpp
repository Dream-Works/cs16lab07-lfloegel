#include "linkedListFuncs.h"
#include "moreLinkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {
  //Test your insertNodeToSortedList function
  //Test your code extensively

  int fiveNums[3]={42,57,61};

  LinkedList *list = arrayToLinkedList(fiveNums,3);
  assertEquals( "[42]->[57]->[61]->null", 
		linkedListToString(list),
		"linkedListToString(list)");

  //first case
  insertNodeToSortedList(list,25);
  //assertTrue(list->head->data == 25,"list->head->data == 25");

  assertEquals( "[25]->[42]->[57]->[61]->null", 
		linkedListToString(list),
		"list after adding 25");

  //second case
  insertNodeToSortedList(list,31);
  //assertTrue(list->head->data == 25,"list->head->data == 25");

  assertEquals( "[25]->[31]->[42]->[57]->[61]->null", 
		linkedListToString(list),
		"list after adding 31");
  
  //clears list
  freeLinkedList(list);
  
  int empty[0]={};
  LinkedList *emptyList = arrayToLinkedList(empty,0);

  list = emptyList;

  //assertTrue(list->head == NULL,"list->head->data == NULL");
  //assertTrue(list->tail == NULL,"list->tail->data == NULL");
  assertEquals( "null", 
		linkedListToString(emptyList),
		"linkedListToString(emptyList)");

  insertNodeToSortedList(list,7);

  //assertTrue(list->head != NULL);
  //if (list->head != NULL) {
    //assertTrue(list->head->data == 7,"list->head->data == 7");
  //}

  //assertTrue(list->tail != NULL);
  //if (list->tail != NULL) {
   // assertTrue(list->tail->data == 7,"list->tail->data == 7)");
  //}

  assertEquals( "[7]->null", 
		linkedListToString(list),
		"list after adding 7");

  //assertTrue(list != NULL,"list != NULL");
  //assertTrue(list->head == list->tail,"list->head == list->tail");

  insertNodeToSortedList(list,-6);

  assertEquals( "[-6]->[7]->null", 
		linkedListToString(list),
		"list after adding -6");
   
 // assertTrue(list->head != NULL);
  //if (list->head != NULL) {
    //assertTrue(list->head->data == -6,"list->head->data == -6");
  //}

  //assertTrue(list->tail != NULL);
  //if (list->tail != NULL) {
    //assertTrue(list->tail->data == 7,"list->tail->data == 7)");
  //}

  insertNodeToSortedList(list,-6);

  assertEquals( "[-6]->[-6]->[7]->null", 
		linkedListToString(list),
		"list after adding -6");


  freeLinkedList(emptyList);
 
  //freeLinkedList(emptyList);
  
  return 0;
}



