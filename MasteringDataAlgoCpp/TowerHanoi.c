/* Tower of Hanoi problem

A B C 

A has some number of disk
Move all to C
Move 1 disk at a time

ONLY smaller disk at TOP

 */

#include <stdio.h>

void TOH(int n, int A, int B, int C){
  if (n > 0) {
    TOH(n-1,A,C,B);
    printf("From %d to %d\n", A, C);
    TOH(n-1,B, A, C);
  }
}


int main(){
  /* Let A = 1, B= 2, C = 3 */
  TOH(4,1,2,3);
  return 0;
}

