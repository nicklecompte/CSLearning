#ifndef HITTABLE_LISTH
#define HITTABLE_LISTH

#include<stdbool.h>
#include<stdlib.h>

// The hittable list will just be a linked list of trees

typedef struct ListNode {
  void *data;
  struct ListNode *next;
} ListNode;

ListNode createEmptyNode(int eltSize) {
  return (ListNode) {.data=malloc(eltSize),.next=0};
}

void appendToListNode(ListNode *ls, void *data, int dataSize) {
  ListNode *curElt = ls;
  ListNode *curNext = ls->next;
  do {
    if (curElt->data == 0) {
      curElt->data = data;
      break;
    }
    if (curNext == 0) {
      ListNode newEmpty = createEmptyNode(dataSize);
      newEmpty.data = data;
      curElt->next = &newEmpty;
      break;
    }
    curElt = curNext;
    curNext = curElt->next;
  } while (curNext > 0);
}

void *getAtIndex(int index, ListNode ls) {
  if (index == 0) {
    return ls.data;
  }
  int curIndex = 0;
  ListNode *curNext = ls.next;
  while (curIndex <= index) {
    if (curNext == 0) {
      return 0;
    }
    curIndex += 1;
    curNext = curNext->next;
  };
  return curNext->data;
}
  
#endif
