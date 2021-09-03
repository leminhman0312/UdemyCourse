#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node
{
  int coeff;
  int exp;
  struct Node *next;
}*poly1=NULL,*poly2=NULL;


struct Node  *create(struct Node *temp_poly){
  struct Node *t,*last;
  int num, i;

  printf("Enter no. of terms\n");
  scanf("%d", &num);

  printf("Enter each term with coeff and exp\n");

  for (i = 0; i < num ; i++) {
    t=(struct Node*)malloc(sizeof(struct Node));
    scanf("%d %d", &t->coeff, &t->exp);
    t->next = NULL;

    /* making the head node to be called temp_poly */
    /* 1st term poly = null, so both temp_poly and last = t */
    if (temp_poly == NULL) {
      temp_poly=t;
      last = t;
    }
    /* more than 1 term */
    /* your last points to current t, making current t the new last */
    /* your current t->next = NULL, so the new last->next = NULL as well */
    else {
      last->next = t;
      last = t;
    }
  }
  return temp_poly;
}


struct Node *createPoly(int nterm){
  struct Node *poly, *last, *t;
  poly = (struct Node*)malloc(sizeof(struct Node));
  int coefficient;
  int exponent;

  printf("Enter coefficient and exponent: ");
  scanf("%d %d", &coefficient, &exponent);

  poly->coeff = coefficient;
  poly->exp = exponent;



  /* special case if only 1 term */
  if (nterm == 1) {
    poly->next = NULL;
  }
  else {
    /* keep adding node until reaches number of terms */
    int count = 1;
    while (count < nterm ) {
      
      last = (struct Node*)malloc(sizeof(struct Node));
      t = (struct Node*)malloc(sizeof(struct Node));

      printf("Enter coefficient and exponent: ");
      scanf("%d %d", &coefficient, &exponent);

      t->coeff = coefficient;
      t->exp = exponent;

      /* set your first node as last */
      last = poly;

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
  
  return poly;
}


double evalPoly(int x, struct Node *p){
  double sum = 0.0;
  struct Node *q = p;
  while (q != NULL) {
    sum += q->coeff*pow(x,q->exp);
    q = q->next;
  }
  return sum;
}




int count(struct Node *p){
  int length=0;
  while (p != NULL) {
    length++;
    p=p->next;
  }
  return length;
}




struct Node *addPoly(struct Node* p1, struct Node *p2, struct Node *result) {

  struct Node *t,*last;

  int length1 = 0, length2 = 0, imax;

  length1 = count(p1);
  length2 = count(p2);

  if (length1 > length2) {
    imax = length1;
  }
  else if (length1 < length2) {
    imax = length2;
  }
  else {
    imax = length1;
  }
  
  
  for (int i = 0; i < imax ; i++) {
     

     t=(struct Node*)malloc(sizeof(struct Node));

     if (p1->exp == p2->exp) {
       t->coeff = p1->coeff+p2->coeff;
       t->exp = p1->exp;
       t->next = NULL;

       p1=p1->next;
       p2=p2->next;
     }
     else if (p1->exp > p2->exp) {
       t->coeff = p1->coeff;
       t->exp = p1->exp;
       t->next = NULL;
       p1 = p1->next;
     }
     else {
       t->coeff = p2->coeff;
       t->exp = p2->exp;
       t->next = NULL;
       p2 = p2->next;
     }

     if (result == NULL) {
       result=t;
       last = t;
     }
     else {
       last->next = t;
       last = t;
     }
   }

  return result;

}

void displayPoly(struct Node *p){
  printf("----- Printing polynomial---------\n");
  while (p != NULL) {
    printf("%d*x^%d + ", p->coeff, p->exp);
    p=p->next;
  }
  printf("\n----------------------------------\n");
}

int main(){

  /* int terms, x; */
  /* printf("Please enter no. of terms and where to evaluate:"); */
  /* scanf("%d %d", &terms, &x); */
  /* struct Node *myPoly; */
  /* myPoly = createPoly(terms); */
  /* displayPoly(myPoly); */
  /* printf("\nResult at x = 0 is %4.2f\n", evalPoly(x, myPoly)); */

  poly1 = create(poly1);
  poly2 = create(poly2);
  printf("Here are the 2 polynomials\n");
  displayPoly(poly1);
  displayPoly(poly2);

  struct Node *add = NULL;

  add = addPoly(poly1, poly2, add);
  printf("\nHere are their sums:\n");
  displayPoly(add);
  return 0;
}
