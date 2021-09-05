/*  

nCr = n! / (r!(n-r)!)

Given A B C D E F G 
How many way to select only 3 unique? 7 C 3 

Value of r from 0 to n => r cannot greater than 5 

*/


#include <stdio.h>

int fact(int n){
  if (n == 0) {
    return 1;
  }
  else {
    return fact(n-1)*n;
  }
}


/* Time O(3n) = O(n) */
int ncr(int n, int r){
  int num, den;
  num = fact(n);
  den = fact(r)*fact(n-r);
  return num/den;
}


/* From pascal triangle, ncr obtained by adding recursively 
     1         => this is 0c0
    1  1       => 1c0 and 1c1
   1 2  1      => 2c0, 2c1, 2c2
 1 3  3  1     => 3c0, 3c1, 3c2, 3c3
1 4  6  4  1   => 4c0, 4c1, 4c2, 4c3, 4c4


For a given nCr = (n-1)C(r-1) + (n-1)Cr

Note when r = 0, return 1 
When n = r , return 1

*/


int ncrRecursion(int n, int r){
  if (r == 0 || n == r) {
    return 1;
  }
  else {
    return ncrRecursion(n-1, r-1) + ncrRecursion(n-1, r);
  }
}


int main(){
  printf("%d\n", ncr(5, 3));
  printf("%d\n", ncrRecursion(5, 3));
  return 0;
}
