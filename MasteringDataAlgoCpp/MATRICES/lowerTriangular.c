#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int *A;
  int n;
};

/* Row major mapping */
void setLowerTriROW(struct Matrix *m, int i, int j, int x){
  if (i >= j) {
    m->A[i*(i-1)/2 + j-1] = x;
  }
}

int getLowerTriROW(struct Matrix *m, int i, int j){
  if (i >= j) {
    return m->A[i*(i-1)/2 + j-1];
  }
  else {
    return 0;
  }
}

void displayROW(struct Matrix m){
  int i, j;
  for (i = 1; i <= m.n ; i++) {
    for (j = 1; j <= m.n ; j++) {
      if (i >= j) {
	printf("%d ", m.A[i*(i-1)/2 + j-1]);
      }
      else {
	printf("0 ");
      }
    }
    printf("\n");
  }
}


/* Col major mapping */
void setLowerTriCOL(struct Matrix *m, int i, int j, int x){
  if (i >= j) {
    m->A[m->n*(j-1)+(j-2)*(j-1)/2 + (i-j)] = x;
  }
}

int getLowerTriCOL(struct Matrix *m, int i, int j){
  if (i >= j) {
    return m->A[m->n*(j-1)+(j-2)*(j-1)/2 + (i-j)]; 
  }
  else {
    return 0;
  }
}

void displayCOL(struct Matrix m){
  int i, j;
  for (i = 1; i <= m.n ; i++) {
    for (j = 1; j <= m.n ; j++) {
      if (i >= j) {
	printf("%d ", m.A[m.n*(j-1)+(j-2)*(j-1)/2 + (i-j)]);
      }
      else {
	printf("0 ");
      }
    }
    printf("\n");
  }
}



int main(){
  int i, j, x;
  struct Matrix m;

  printf("Enter dimension\n");
  scanf("%d", &m.n);

  
  m.A = (int *)malloc(sizeof(int) * m.n*(m.n+1)/2);

  printf("Enter all elements\n");
  for (i = 1; i <= m.n ; i++) {
    for (j = 1; j <= m.n ; j++) {
      scanf("%d", &x);
      setLowerTriCOL(&m, i, j, x);
    }
  }
  printf("\n");
  displayCOL(m);
  return 0;
}
