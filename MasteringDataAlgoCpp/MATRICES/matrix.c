#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int *A;
  int Adiagonal[10];
  int n;
};


/* DIAGONAL MATRIX */
void setDiag (struct Matrix *m, int i, int j, int x){
  if (i == j) {
    m->Adiagonal[i-1] = x;
  }
}

int getDiag(struct Matrix m, int i, int j){
  if (i == j) {
    return m.Adiagonal[i-1];
  }
  else {
    return 0;
  }
}

void displayMatrix(struct Matrix m){
  int i, j;
  for (i = 0; i < m.n ; i++) {
    for (j = 0; j < m.n ; j++) {
      if (i == j) {
	printf("%d ", m.A[i]);
      }
      else {
	printf("0 ");
      }
    }
    printf("\n");
  }
}

/* LOWER TRIANGULAR */
void setLowerTri(struct Matrix *m, int i, int j, int x){
  if (i >= j) {
    m->A[i*(i-1)/2 + j-1] = x;
  }
}

int getLowerTri(struct Matrix *m, int i, int j){
  if (i >= j) {
    return m->A[i*(i-1)/2 + j-1];
  }
  else {
    return 0;
  }
}


void displayLowerTriangular(struct Matrix m){
  int i, j;
  for (i = 1; i <= m.n ; i++) {
    for (j = 1; j <= m.n ; j++) {
      if (i == j) {
	printf("%d ", m.A[i*(i-1)/2 + j-1]);
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
      setLowerTri(&m, i, j, x);
    }
  }
  printf("\n");
  displayLowerTriangular(m);
  return 0;
}
