/* Sum of n natural number */
/* Eg: 1 + 2 + 3 + 4 + 5 + 6 + 7  */
/* Let sum(n) = 1+2+3+...+(n-1) + n */
/* or sum (n) = sum(n-1) + n */

/* In other words */
/* sum(n) =  sum (n-1) + n if n > 0*/
/* sum(n) = 0 if n  = 0 */

#include <stdio.h>

/* Time O(1) */
int sumFormula(int n){
  return(n*(n+1))/2;
}

/* Time O(n) */
int sumLoop(int n){
  int i, s = 0;
  for (i = 1; i <= n ; i++) {
    s = s + i;
  }
  return s;
}

/* Time O(n), Space O(n) */
int sumRecursive(int n){
  if (n == 0) {
    return 0;
  }
  else {
    return sumRecursive(n-1)+n;
  }
}

int main(){
  int n = 5;
  int r = sumLoop(n);
  printf("%d\n", r);
  return 0;
}

