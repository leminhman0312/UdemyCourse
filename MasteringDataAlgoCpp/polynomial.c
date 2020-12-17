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

int main(){
  struct Poly p;
  printf("Enter no. of non zero terms\n");
  scanf("%d", &p.n);
  p.t = (int*)malloc(sizeof(int) * p.n);

  printf("Enter polynomial term\n");
  for (int i = 0; i < p.n ; i++) {
    printf("Enter term %d\n", i++);
    scanf("%d%d\n", &p.t[i].coeff, &p.t[i].exp);

  }


  return 0;
}
