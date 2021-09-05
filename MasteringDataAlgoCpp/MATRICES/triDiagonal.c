#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int *A;
  int n;
};

void display(struct Matrix m){
  int i, j, diff;

  for (i = 1; i <= m.n ; i++) {
    for (j = 1; j <= m.n  ; j++) {
      diff = i-j;
      if (diff == 1) {
	printf("%d\t", m.A[i-2]);
      }
      
      else if (diff == 0) {
	printf("%d\t", m.A[m.n-1 + i-1]);
      }
      
      else if (diff == -1) {
	printf("%d\t",m.A[(2*m.n)-1 + i - 1]);
      }
      
      else {
	printf("0\t");
      }
    }
    printf("\n");
  }

}

int main(){
  struct Matrix m;

  m.n = 5;
  int sizeA = (3*m.n)-2; 
  
  m.A = (int *)malloc(sizeof(int) * sizeA);

  for (int iA = 0; iA < sizeA ; iA++) {
    m.A[iA] = iA+1;
  }
  
  display(m);
  
  

  return 0;
}

