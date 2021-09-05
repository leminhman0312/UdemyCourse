#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>



/* Node structure */
struct Node
{
  int data;
  struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;

/* Create LL from an array input */
void create1(int A[], int n){
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

void create2(int A[], int n){
  int i;
  struct Node *t, *last;
  second = (struct Node*)malloc(sizeof(struct Node));
  second->data = A[0];
  second->next = NULL;
  last = second;

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


/* find the intersection */
struct Node *intersection(struct Node *head1, struct Node *head2){

  struct Node *p1 = head1;
  struct Node *p2 = head2;
  
  while (p1->data != p2->data) {

    /* printf("---------------------\n"); */
    /* printf("p1->data = %d\n", p1->data); */
    /* printf("p2->data = %d\n", p2->data); */
    /* printf("---------------------\n"); */
    
    /* 1st LL hits end */
    if (p1->next == NULL) {
      p1 = head2;
    }
    /* keep marching */
    else {
      p1=p1->next;
    }

    /* 2nd LL hits end */
    if (p2->next == NULL) {
      p2 = head1;
    }
    /* keep marching */
    else {
      p2=p2->next;
    }
  }
  return p1;
}
  


/* main program */
int main(){
  /* Create 1st LL */
  int A[] = {8,6,3,9,10,4,2,12};
  create1(A, 8);
  /* printf("First LL:\n"); */
  /* display(first); */
  /* printf("\n"); */

  /* Create 2nd LL */
  int B[] = {20,30,40,10,4,2,12};
  create2(B, 7);
  /* printf("Second LL:\n"); */
  /* display(second); */
  /* printf("\n"); */

  /* Finding intersection */
  struct Node *res = intersection(first, second);
  printf("Intersection at %d\n", res->data);
  return 0;
}
