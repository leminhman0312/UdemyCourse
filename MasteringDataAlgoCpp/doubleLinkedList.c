#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *prev;
  int data;
  struct Node *next;
}*first = NULL;



void Create(int A[], int n){
  struct Node *t, *last;
  int i;

  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = A[0];
  first->prev = first->next = NULL;
  last = first;

  for (i = 1; i < n ; i++) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];

    /* make t->next to be NULL */
    /* t->next = last->next; */
    t->next = NULL;

    /* current t goes AFTER previous NODE */
    t->prev = last;

    /* previous NODE no longer ends with NULL, now it points to the next NODE */
    last->next = t;

    /* Rename/Update the new LAST */
    last = t;
  }
}

void Display(struct Node *p){
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}

int Length(struct Node *p){
  int len = 0;
  while (p != NULL) {
    len++;
    p = p->next;
  }
  return len;
}


void Insert(struct Node *p, int index, int x){
  struct Node *t;
  int i;

  if (index < 0 || index > Length(p)) {
    return;
  }

  /* Insert before first */
  if (index == 0) {
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->prev = NULL;
    t->next = first;
    first->prev = t;
    first = t;
  }


  /* Insert at other position */
  else {
   for (i = 0; i < index-1 ; i++) {
     p = p->next;
   }
   t = (struct Node*)malloc(sizeof(struct Node));
   t->data = x;

   t->prev = p;
   t->next = p->next;
   if (p->next != NULL) {
     p->next->prev = t;
   }
   p->next = t;
  }
}




int main(){
  int A[] = {10,20,30,40,50,60};
  Create(A,6);
  Insert(first, 6, 25);
  Display(first);
  return 0;
}
