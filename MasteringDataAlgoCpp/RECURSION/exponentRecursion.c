/* Exponent (m)^n 
   2^5 = 2 x 2 x 2 x 2 x 2 
   m^n = m x m x m for n times
   pow(m,n) => m x m x m for (n-1) times then x m 
   Eg. 2 ^ 5 = (2 ^ 4) x 2  
   
   pow(m,n) = pow(m,n-1) x m
   
   So...

   pow(m,n) = pow(m,n-1) for n > 0
   pow(mn,n) = 1 if n = 0
*/


#include <stdio.h>

/* Time O(N) Space O(N) */
int power(int m, int n){
  if (n == 0) {
    return 1;
  }
  else {
    return power(m,n-1)*m;
  }
}

int powerLoop(int m, int n){
  int result = 1;
  while (n != 0) {
    result = result * m;
    n--;
  }
  return result;
}

int powOddEven(int m, int n){
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return powOddEven(m*m, n/2);
  }
  else {
    return m*powOddEven(m*m,(n-1)/2);
  }
}


int main(){
  int r = powerLoop(2,4);
  printf("%d\n", r);
  return 0;
}
