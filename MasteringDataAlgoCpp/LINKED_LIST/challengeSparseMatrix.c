#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int col;
  int data;
  struct Node *next;
}*first = NULL;

/* ai = A[i] , x = number of non zero elements*/
struct Node *createSparse(struct Node *ai, int x){

  struct Node *last, *t;
  ai = (struct Node*)malloc(sizeof(struct Node));
  int column;
  int value;

  printf("Enter col and value: ");
  scanf("%d %d", &column, &value);

  ai->col = column;
  ai->data = value;


  int count = 1;

  /* special case if only 1 non zero element */
  if (x == 1) {
    ai->next = NULL;
  }
  else {
    /* keep adding node until reaches number of non zero */
    while (count < x ) {
      
      last = (struct Node*)malloc(sizeof(struct Node));
      t = (struct Node*)malloc(sizeof(struct Node));

      printf("Enter col and value: ");
      scanf("%d %d", &column, &value);

      t->data = value;
      t->col = column;

      /* set your first node as last */
      last = ai;

      /* bring a pointer last to the node before NULL. Eg: */
      /* [ai]->[x]->NULL.  Here last would at the [x] position */
      /* Then manipulate so x/last->t, t->NULL becomes the last node */
      /* [ai]->[x]->[t]->NULL */
      
      while (last->next != NULL) {
	last = last->next;
      }
      last->next = t;
      t->next = NULL;

      count++;
    }
  }
  
  return ai;

}



void display(struct Node *p){

  while (p != NULL) {
    printf("COL: %d DATA: %d\n", p->col, p->data);
    p=p->next;
  }
}


int main(){

  /* An m x n matrix */
  int m = 5;
  int n = 6;

  struct Node *A[m];		/* define an array of m node pointers */
  for (int i = 0; i < m ; i++) {
    A[i] = NULL;                /* initializes the arrays to NULL */
  }


  int number_non_zero = 0;

  
  /* Creating matrix */
  printf("CREATING MATRIX FROM USER INPUTS\n");
  for (int i = 0; i < m ; i++) {
    printf("-----------------------------------------------------\n");
    printf("ROW = %d. Please enter # of non zero elements\n", i);
    scanf("%d", &number_non_zero);
    printf("-----------------------------------------------------\n");
    A[i] = createSparse(A[i], number_non_zero);
  }


  
  /* printing matrix */
  printf("\nPRINTING THE SPARSE MATRIX\n");
  struct Node *p;
  for (int i = 0; i < 5 ; i++) {
    p = A[i];
    for (int j = 0; j < 6 ; j++) {

      if (j == p->col) {
	printf("%d\t", p->data);
	if (p->next != NULL) {
	  p = p->next;
	}
      }
      else {
	printf("0\t");
      }
    }
    printf("\n");

  }



  return 0;
}
