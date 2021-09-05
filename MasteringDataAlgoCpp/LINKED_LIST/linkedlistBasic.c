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


/* recursive to display time  O(n) space O(n+1)*/
void displayRecursive(struct Node *p){
  if (p != NULL) {
    printf("%d\n", p->data);
    displayRecursive(p->next);
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


int Rcount(struct Node *p){
  if (p != NULL) {
    return Rcount(p->next) + 1;
  }
  else {
    return 0;
  }
}


/* sum element */
int sum (struct Node *p){
  int s = 0;
  while (p != NULL) {
    s = s + p->data;
    p = p->next;
  }
  return s;
}

int Rsum(struct Node *p){
  if (p == NULL) {
    return 0;
  }
  else {
    return Rsum(p->next)+p->data;
  }
}


/* Max iterative */
int max(struct Node *p){
  int max = INT_MIN;

  while (p != NULL) {
    if (p->data > max) {
      max = p->data;
    }
    p = p->next;
  }
  return max;
}

/* Max recursive */
int RMax(struct Node *p){
  int x = 0;
  if (p == NULL) {
    return INT_MIN;
  }
  x = RMax(p->next);
  if (x > p->data) {
    return x;
  }
  else {
    return p->data;
  }
}

/* Iterative linear search */
struct Node *LSearch(struct Node *p, int key){

  while (p != NULL) {
    if (key == p->data) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

/* Recursive linear search */
struct Node *RSearch(struct Node *p, int key){
  if (p == NULL) {
    return NULL;
  }
  if (key == p->data) {
    return p;
  }
  return RSearch(p->next, key);
}

/* Improved Linear Search Move to Head */
struct Node *LHeadSearch(struct Node *p, int key){

  struct Node *q;		/* previous pointer */
  
  while (p != NULL) {
    if (key == p->data) {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q = p;
    p = p->next;
  }
  return NULL;
}

/* Insert  */
void insert(struct Node *p, int index, int x){

  struct Node *t;
  int i;

  /* check if index is valid */
  if (index < 0 || index > count(p)) {
    return;
  }

  t = (struct Node*)malloc(sizeof(struct Node));
  t->data = x;

  /* BEFORE first */
  if (index == 0) {
    t->next = first;
    first = t;
  }
  /* AFTER certain node */
  else {
    for (i = 0; i < index - 1 && p != NULL; i++) {
      p=p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

/* Special only insert at last */
void InsertLast(int x){
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  struct Node *last = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;


  if (first == NULL) {
    first = t;
    last = t;
  }
  else {
    last = first;
    while (last->next != NULL) {
      last = last->next;
    }
    last->next = t;
    last = t;
  }
}


/* Insert in Sorted LinkedList */
void SortedInsert(struct Node *p, int x){
  struct Node *t, *q = NULL;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;

  /* if no node exists, just insert the node */
  if (first == NULL) {
    first = t;
  }
  /* we have to insert in a list */
  else {
    while (p != NULL && p->data < x) {
      q = p;
      p = p->next;
    }

    /* if stop before existing first node, then insert on the left */
    if (p == first) {
      t->next = first;
      first = t;		/* making t to become the new "first" */
    }
    /* have to insert between p and q pointer */
    else {
      t->next = q->next;
      q->next = t;
    }
  }
}



/* Delete nodde from a list */
int Delete(struct Node *p, int index){
  struct Node *q = NULL;
  int i, x = -1;

  /* check if index is valid */
  if (index < 1 || index > count(p)) {
    return -1;
  }

  if (index == 1) {
    q = first;
    x = first->data;
    first = first->next;
    free(q);
    return x;
  }
  else {
    for (i = 0; i < index-1 ; i++) {
      q=p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }
}


/* Check if sorted */
int isSorted(struct Node *p){
  int x = -65536;
  while (p != NULL) {
    if (p->data < x) {
      return 0;
    }
    x = p->data;
    p = p->next;
  }
  return 1;
}

/* Remove duplicates */
void RemoveDuplicates(struct Node *p){
  struct Node *q = p->next;

  while (q != NULL) {
    if (p->data != q->data) {
      p = q;
      q = q->next;
    }
    else {
      p->next = q->next;
      free(q);
      q = p->next;
    }
  }
}


/* Reversing linkedlist */

void Reverse1(struct Node *p){
  int *A, i = 0;
  A = (int *)malloc(sizeof(int) * count(p));
  struct Node *q = p;

  while (q != NULL) {
    A[i] = q->data;
    q= q->next;
    i++;
  }

  q = p;
  i--;
  while (q != NULL) {
    q->data = A[i];
    q=q->next;
    i--;
  }
}


void Reverse2(struct Node *p){
  struct Node *q=NULL, *r = NULL;
  while (p != NULL) {
    r = q;
    q = p;
    p = p->next;

    q->next = r;
  }
  first = q;
}

void Reverse3(struct Node *q, struct Node *p){
  if (p != NULL) {
    Reverse3(p, p->next);
    p->next = q;
  }
  else {
    first = q;
  }
}


/* Concatenating */
void Concat(struct Node *p, struct Node *q){
  third=p;
  while (p->next != NULL) {
    p=p->next;
  }
  p->next = q;
}


/* Merging */
void Merge(struct Node *p, struct Node *q){
  struct Node *last;

  /* Set first in merged list */
  if (p->data < q->data) {
    last = p;
    third = p;
    p = p->next;
    third->next = NULL;
  }else {
    last = q;
    third = q;
    q = q->next;
    third->next = NULL;
  }

  /* Populate merged list */
  while (p != NULL && q != NULL) {
    printf("%d\t%d\n", p->data, q->data);
    if (p->data < q->data) {
      last->next = p;
      last = p;
      p = p->next;
      last->next = NULL;
    }
    else {
      last->next = q;
      last = q;
      q = q->next;
      last->next = NULL;
    }
  }
  if (p != NULL) {
    last->next = p;
  }
  if (q != NULL) {
    last->next = q;
  }
}


int isLoop(struct Node *f){
  struct Node *q, *p;
  q = p = f;
  do
    {
      p = p->next;
      q = q->next;
      if (q != NULL) {
	q = q->next;
      }
      else {
	q = q;
      }
    } while (p != NULL && q != NULL && p != q);

  if (p == q) {
    return 1;
  }
  else {
    return 0;
  }
  
}

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






int main(){
  /* struct Node *t1, *t2; */
  int A[] = {8,6,3,9,10,4,2};
  create(A, 7);
  display(first);
  findMiddleV2(first);

  
  return 0;
}

