#include "hittable_list.h"

#include<stdio.h>

int main() {
  ListNode simpls = createEmptyNode(sizeof(char *));
  char *hello = "hello";
  simpls.data = hello;
  printf("Data : %s",(char *)simpls.data);
  ListNode ls = createEmptyNode(sizeof(int));
  for (int i = 1; i <= 10; i++) {
    int data = (i % 3) * i;
    printf("Data : %i",data);
    appendToListNode(&ls,&data,sizeof(int));
  }
  for (int j = 0; j <= 9; j++) {
    int output = *(int*)getAtIndex(j,ls);
    printf("%i\n",output);
  }
  printf("Done");
  return 0;
}
