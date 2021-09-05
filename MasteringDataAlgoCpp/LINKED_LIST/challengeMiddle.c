#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct Node
{
  int data;
  struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;

void create(int A[], int n){
  int i;
  struct Node *t, *last;
  first = (struct Node*)malloc(sizeof(struct Node));
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (i = 1; i < n ; i++) {
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data=A[i];
    t->next = NULL;
    last->next = t;
    last=t;
  }
}

/* loop display O(n) */
void display(struct Node *p){
  while (p != NULL) {
    printf("%d\n", p->data);
    p=p->next;
  }
}



/* count nodes in linkedlist */
int count(struct Node *p){
  int length=0;
  while (p != NULL) {
    length++;
    p=p->next;
  }
  return length;
}

/* find the middle node using length*/
void findMiddleV1(struct Node* p){
  int length = 0;
  int i;
  int mid;
  length = count(p);
  mid = (int) ceil( (double) length/2);
  printf("The length is %d\n", length);
  printf("Middle index is at %d\n", mid);

  for (i = 1; i <= mid-1 ; i++) {
    p = p->next;
  }
  printf("Currently, data = %d \n", p->data);
}

/* find the middle node using 2 pointers */
void findMiddleV2(struct Node *h){
  struct Node *q, *p;

  p = q = h;

  while (q != NULL) {
    /* 1st movement of q */
    q = q->next;
    if (q != NULL) {
      /* 2nd movement of q */
      q = q->next;
    }
    if (q != NULL) {
      p = p->next;
    }
  }
  printf("Middle node is %d\n", p->data);
}

/* main code */
int main(){
  /* struct Node *t1, *t2; */
  int A[] = {8,6,3,9,10,4,2};
  create(A, 7);
  display(first);
  findMiddleV2(first);

  
  return 0;
}

