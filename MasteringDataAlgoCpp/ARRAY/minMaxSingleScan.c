/* Find min max in given list of element */

#include <stdio.h>


/* time O(n) */
/* min time n-1 for descending BEST */
/* max time 2(n-1) for ascending  WORST*/

void minmax(int *arr){
  int min = arr[0];
  int max = arr[0];

  for (int i = 1; i < 10 ; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
    else if (arr[i] > max) {
      max = arr[i];
    }
  }
  printf("Max = %d\n", max);
  printf("Min = %d\n", min);
}


int main(){

  int a[10] = {5,8,3,9,6,2,10,7,-1,4};
  minmax(a);
  return 0;
}
