/* 
Taylor series:

e^x = 1 + (x /1!) + (x^2/2!) + ..... 

Need 3 things: add, power, factorial
Consider only up to 4th term

e^x = 1 + (x /1!) + (x^2/2!) + (x^3/3!) + (x^4/4!) = e(x,4)

Let p be the numerator, and f be the denominator
 */
#include <stdio.h>
double e(int x , int n){
  static double p = 1, f = 1;
  double r;
  if (n == 0) {
    return 1;
  }
  else {
    r = e(x,n-1);
    p = p * x;
    f = f * n;
    return r + p/f;
  }
}


/* Using Homer rule 

e^x = 1 +  (x/1) + (x^2/1*2) + (x^3/1*2*3) + (x^4/1*2*3*4)

1 + (x/1)*[1 + x/2 + x^2/2*3 + x^3/2*3*4]

1+ (x/1)*x/2*[1+x/3 + x^2/3*4 ]

Finally....
1 + (x/1)*[1+(x/2) * [1+ (x/3)*[1 + x /4]]]

Order multiplication is now O(n), before was O(n^2)
*/



double eHomerLoop(int x, int n){
  double s = 1;
  while (n > 0) {
    s = 1 + ((double) x/(double) n)*s;
    n--;
  }
  return s;
}

double eHomerRecursive(int x, int n){
  static double s = 1;
  if (n == 0) {
    return s;
  }
  else {
    s = 1 + ((double)x/(double)n)*s;
  }
  return eHomerRecursive(x,n-1);
}


double eIterative(int x , int n){
  double s = 1;
  int i;
  double num = 1, den = 1;
  for (i = 1; i < n ; i++) {
    num = num * x;
    den = den * i;
    s = s + (num/den);
  }
  return s;
}



int main(){
  double result = eIterative(1, 10);
  printf("%lf\n", result);
  return 0;
}

