#include <stdio.h>
#include <stdlib.h>

int main(){
  /* on Stack */
  int A[3][4] = {{1,2,3,4},{2,4,6,8},{1,3,5,7}};

  /* Row on stack, col on Heap */
  int *B[3];
  B[0] = (int*)malloc(sizeof(int) * 4);
  B[1] = (int*)malloc(sizeof(int) * 4);
  B[2] = (int*)malloc(sizeof(int) * 4);

  /* All on stack */
  int **C;
  C=(int**)malloc(sizeof(int*) * 3);
  C[0] = (int*)malloc(sizeof(int) * 4);
  C[1] = (int*)malloc(sizeof(int) * 4);
  C[2] = (int*)malloc(sizeof(int) * 4);

  /* Print out arrays */
  int i, j;

  for (i = 0; i < 3 ; i++) {
    for (j = 0; j < 4 ; j++) {
      printf("%d\t", A[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  for (i = 0; i < 3 ; i++) {
    for (j = 0; j < 4 ; j++) {
      printf("%d\t", B[i][j]);
    }
    printf("\n");
  }
  
  printf("\n");
  for (i = 0; i < 3 ; i++) {
    for (j = 0; j < 4 ; j++) {
      printf("%d\t", C[i][j]);
    }
    printf("\n");
  }
  return 0;
}
