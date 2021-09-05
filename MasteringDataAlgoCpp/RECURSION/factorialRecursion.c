/* Factorial of a number */
/* n! = 1 x 2 x 3..... x n  */
/* 0! = 1! = 1 */

/* fact(n) = 1 x 2 x 3 x 4 x ..... x (n-1) x n */
/* fact(n) = fact(n-1) x n */

#include <stdio.h>

int fact(int n){
  if (n == 0) {
    return 1;
  }
  else {
    return fact(n-1)*n;
  }
}


int Ifact(int n){
  int f = 1;
  int i;
  for (int i = 1; i <= n ; i++) {
    f = f*i;
  }
  return f;
}


int main(){
  int r = Ifact(5);
  printf("%d ", r);
  return 0;
}
