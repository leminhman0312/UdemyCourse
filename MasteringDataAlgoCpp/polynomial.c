#include <stdio.h>
#include <stdlib.h>

struct Term
{
  int coeff;
  int exp;
};

struct Poly
{
  int n;
  struct Term *t;
};

void create(struct Poly *p){
  int i;
  printf("Enter no. of terms\n");
  scanf("%d", &p->n);
  p->t = (struct Term*)malloc(sizeof(struct Term) * p->n);

  printf("Enter polynomial term\n");
  for (i = 0; i < p->n ; i++) {
    scanf("%d%d", &p->t[i].coeff, &p->t[i].exp);
  }
}

struct Poly *add(struct Poly *p1, struct Poly *p2){

  int i,j,k;
  struct Poly *sum;
  sum = (struct Poly*)malloc(sizeof(struct Poly));
  sum->t=(struct Term*)malloc(sizeof(struct Term) * p1->n+p2->n);
  i = j = k = 0;

  while (i<p1->n && j < p2->n) {
    if (p1->t[i].exp > p2->t[j].exp) {
      sum->t[k] = p1->t[i];
      i++;
      k++;
    }
    else if (p2->t[j].exp > p1->t[i].exp) {
      sum->t[k] = p2->t[j];
      j++;
      k++;
    }
    else {
      sum->t[k].exp = p1->t[i].exp;
      sum->t[k].coeff = p1->t[i].coeff + p2->t[j].coeff;
      i++;
      j++;
      k++;
    }
  }

  /* copy the remaining  */
  for( ; i < p1->n ; i++) {
    sum->t[k] = p1->t[i];
    k++;
  }

  for( ; j < p2->n ; j++) {
    sum->t[k] = p2->t[j];
    k++;
  }

  sum->n = k;
  return sum;
}


void display(struct Poly p){
  int i;
  for (i = 0; i < p.n ; i++) {
    if (i == p.n-1) {
      printf("%dx^%d", p.t[i].coeff, p.t[i].exp);
    }
    else {
      printf("%dx^%d + ", p.t[i].coeff, p.t[i].exp);
    }
  }
  
  printf("\n");
}

int main(){
  struct Poly p1,p2,*p3;
  create(&p1);
  create(&p2);
  p3 = add(&p1,&p2);

  printf("\n");
  display(p1);
  printf("\n");
  display(p2);
  printf("\n");
  display(*p3);
  
  return 0;
}
