/* Find pair with sum in sorted array */

#include <stdio.h>

// linear time O(n)
void pairSumSorted(int *arr, int k){
  int i = 0;
  int j = 9;
  int sum;
  
  while (i < j) {
    sum = arr[i] + arr[j];
    if (sum > k) {
      j--;
    }
    else if (sum < k) {
      i++;
    }
    else {
      printf("%d + %d = %d\n", arr[i], arr[j], k);
      i++;
      j--;
    }
  }
}


// using for loop
void pairSumSortedFor(int *arr, int k){
  int sum = 0;
  int i, j;

  for (i = 0, j = 9 ; i < j ; ) {
    sum = arr[i] + arr[j];
    if (sum > k) {
      j--;
    }
    else if (sum < k) {
      i++;
    }
    else {
      printf("%d + %d = %d\n", arr[i], arr[j], k);
      i++;
      j--;
    }
  }
}

int main(){
  int a[10] = {1,3,4,5,6,8,9,10,12,14};
  // pairSumSorted(a , 10);
  pairSumSortedFor(a, 10);
  return 0;
}
