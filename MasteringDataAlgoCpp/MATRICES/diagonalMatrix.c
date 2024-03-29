#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int A[10];
  int n;
};


/* DIAGONAL MATRIX */
void setDiag (struct Matrix *m, int i, int j, int x){
  if (i == j) {
    m->A[i-1] = x;
  }
}

int getDiag(struct Matrix m, int i, int j){
  if (i == j) {
    return m.A[i-1];
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



int main(){
  struct Matrix m;
  m.n = 4;
  setDiag(&m,1,1,5);
  setDiag(&m,2,2,8);
  setDiag(&m,3,3,9);
  setDiag(&m,4,4,12);
  printf("%d \n",getDiag(m,2,2));
  displayMatrix(m);
  return 0;
}
