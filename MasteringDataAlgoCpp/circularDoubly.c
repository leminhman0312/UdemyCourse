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
  first->next = first;
  first->prev = first->next;
  last = first;

  for (i = 1; i < n ; i++) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[i];

    // Inner links
    last->next=t;
    t->prev=last;

    // Outer links
    t->next = first;
    first->prev = t;
    

    /* Rename/Update the new LAST */
    last = t;
  }
}


// Display 
void Display(struct Node *p){
  printf("Printing....\n");
  do
    {
      printf("%d\n", p->data);
      p = p->next;
    } while (p != first);

  printf("Finished Printing\n");
  
}

// Calculate Length
int Length(struct Node *p){
  int len = 0;
  do
    {
      len++;
      p = p->next;
    } while (p != first);
  return len;
}

// Insert nodes
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

    // outside links
    first->prev->next = t;
    t->prev = first->prev;

    // middle links
    t->next = first;
    first->prev = t;

    // update first
    first = t;
  }


  /* Insert at other position */
  else {

    // take a pointer up to the position before
    for (i = 0; i < index-1 ; i++) {
      p = p->next;
    }

    // create new node
    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;


    // modify links
    t->prev = p;
    if (p->next == first) {
      t->next = first;
      first->prev = t;
    }
    else {
      t->next = p->next;
      p->next->prev = t;
    }
    p->next = t;
  }
}



int main(){
  int A[] = {10,20,30};
  Create(A,3);
  Insert(first, 3, 99);
  Display(first);
  
  return 0;
}


