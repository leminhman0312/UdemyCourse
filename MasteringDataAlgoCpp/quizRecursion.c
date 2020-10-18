#include <stdio.h>

/* Question 1 */
int f(int n){
  static int i = 1;
  printf("%d\t%d\n", n, i );
  if (n >= 5) {
    return n;
  }
  n = n + i;
  i++;
  return f(n);
}


/* Question 2 */
void foo(int n, int sum){
  int k = 0, j = 0;
  if (n == 0) {
    return;
  }

  k = n % 10;
  j = n / 10;
  sum = sum + k;
  foo(j,sum);
  printf("%d\n", k);
}



int fun(int n){
  int x = 1, k;

  if (n==1) {
    return x;
  }

  for (k = 1; k < n ; k++) {
    x = x + fun(k)*fun(n-k);
  }
  printf("%d\t%d\n", n , x);
  return x;
}

void count(int n){
  static int d = 1;
  printf("%d\n", n);
  printf("%d\n", d);

  d++;

  if (n > 1) {
    count(n-1);
  }
  printf("%d\n", d);
}

int main(){
  count(3);
  return 0;
}

