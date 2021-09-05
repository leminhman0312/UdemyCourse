/* Fibonacci Series

0 1 1 2 3 5 8 13
0 1 2 3 4 5 6 7

[0 1] starting term

fib(n) = fib(n-2) + fib(n-1) when n > 1 
fib(n) = 1                   when n = 1 
fib(n) = 0                   when n = 0
*/

#include <stdio.h>


/* Time approx O(2^n) */
/* Excessive recursion */
int fib(int n){
  if (n <= 1) {
    return n;
  }
  else {
    return fib(n-2) + fib(n-1);
  }
}


/* To avoid repeated calls */
int F[10]; 			/* some global array F to store the memoir */

int fibMemoir(int n){
  if (n <= 1) {
    F[n] = n;
    return n;
  }
  else {
    if (F[n-2] == -1) {
      F[n-2] = fibMemoir(n-2);
    }
    if (F[n-1] == -1) {
      F[n-1] = fibMemoir(n-1);
    }
    F[n] = F[n-2] + F[n-1];
    return F[n-2] + F[n-1];
  }
}




/* Time O(n) */
int fibIter(int n){
  if (n <= 1) {
    return n;
  }
  else {
    int t0 = 0, t1 = 1;		/* 1 time */
    int s;			/* 1 time */
    for (int i = 2; i < n ; i++) { /* n time */
      s = t0 + t1;		   /* n-1  */
      t0 = t1;			   /* n-1 */
      t1 = s;			   /* n-1 */
    }
    return s;			/* 1 time */
  }
}


int main(){

  for (int i = 0; i < 10 ; i++) {
    F[i] = -1;
  }
    
  printf("%d\n", fibMemoir(5));
  return 0;
}
