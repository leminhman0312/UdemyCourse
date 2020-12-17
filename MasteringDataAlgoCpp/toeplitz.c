#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int *A;
  int n;
};

void setA(struct Matrix m){
  for (int i = 0; i < (m.n + m.n -1) ; i++) {
    m.A[i] = i + 2;
  }
  
  /* for (int i = 0; i < (m.n + m.n -1) ; i++) { */
  /*   printf("%d\n", m.A[i]); */
  /* } */
}

void displayM(struct Matrix m){
  for (int i = 1; i <= m.n ; i++) {
    for (int j = 1; j <= m.n ; j++) {
      if (i <= j) {
	printf("%d\t", m.A[j-i]);
      }
      else if (i > j) {
	printf("%d\t", m.A[m.n + i - j - 1]);
      }
    }
    printf("\n");
  }
}

int main(){
  struct Matrix m;
  m.n = 5;
  m.A = (int*) malloc(sizeof(int) * (m.n + m.n -1));
  setA(m);
  displayM(m);

  

  
  return 0;
}


