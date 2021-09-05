#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
  int *A;
  int n;
};


/* Col major mapping */
void set(struct Matrix *m, int i, int j, int x){
  if (i >= j) {
    m->A[m->n*(j-1)+(j-2)*(j-1)/2 + (i-j)] = x;
  }

}

int get(struct Matrix *m, int i, int j){
  if (i >= j) {
    return m->A[m->n*(j-1)+(j-2)*(j-1)/2 + (i-j)]; 
  }
  else {
    return 0;
  }
}

void display(struct Matrix m){
  int i, j;
  for (i = 1; i <= m.n ; i++) {
    for (j = 1; j <= m.n ; j++) {
      /* set Lower Triangular */
      if (i >= j) {
	printf("%d ", m.A[m.n*(j-1)+(j-2)*(j-1)/2 + (i-j)]);
      }
      /* print the same index but flipped for A[i,j] = A[j,i] */
      else {
	printf("%d ", m.A[m.n*(i-1)+(i-2)*(i-1)/2 + (j-i)]);
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
      set(&m, i, j, x);
    }
  }
  printf("\n");
  display(m);
  return 0;
}
