#include "linkedListFuncs.h"
#include "moreLinkedListFuncs.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {
  //Test your insertNodeToSortedList function
  //Test your code extensively

  int threeNums[3]={42,57,61};
  LinkedList *list = arrayToLinkedList(threeNums,3);

  //delete 61, then 57, then 10

  assertEquals("[42]->[57]->[61]->null", 
    linkedListToString(list),
    "linkedListToString(list)");

  //second case
  deleteNodeRecursively(list,61);

  assertEquals("[42]->[57]->null", 
    linkedListToString(list),
    "recursive delete: list after deleting 61");

  //third case
  deleteNodeRecursively(list,57);

  assertEquals("[42]->null", 
   linkedListToString(list),
    "recursive delete: list after deleting 57");

  deleteNodeRecursively(list,79);

  assertEquals("[42]->null", 
   linkedListToString(list),
    "recursive delete: list after attempting to delete value that doesn't exist in the list");
  
  //clears list
  freeLinkedList(list);

  int empty[0]={};
  LinkedList *emptyList = arrayToLinkedList(empty,0);

  list = emptyList;

  assertEquals("null", 
    linkedListToString(list),
    "recursive delete: attempting to delete from an empty list");

  freeLinkedList(emptyList);




  int fourNums[4]={42,57,61,82};

  //delete 61, then 57, then 10

  LinkedList *fiveList = arrayToLinkedList(fourNums,4);

  list = fiveList;

  assertEquals("[42]->[57]->[61]->[82]->null", 
    linkedListToString(list),
    "linkedListToString(list)");

  //first case
  /*deleteNodeIteratively(list,42);

  assertEquals( "[57]->[61]->[82]->null", 
    linkedListToString(list),
    "interative delete: list after deleting 42"); 
  */

 /*deleteNodeIteratively(list,42);

  assertEquals( "[57]->[61]->[82]->null", 
    linkedListToString(list),
    "interative delete: list after deleting 42"); 
  */

  //second case
  deleteNodeIteratively(list,61);

  assertEquals("[42]->[57]->[57]->[82]->null", 
    linkedListToString(list),
    "iterative delete: list after deleting 61");

  //third case
  deleteNodeIteratively(list,82);

  assertEquals("[42]->[57]->[57]->null", 
   linkedListToString(list),
    "iterative delete: list after deleting 82");

  //fourth case
  /*deleteNodeIteratively(list,57);

  assertEquals("[42]->null",
    linkedListToString(list),
    "interactive delete: list after deleting 57");
  */
  //clears list
  freeLinkedList(fiveList);




  //newDelete

  
 
  
  return 0;
}



