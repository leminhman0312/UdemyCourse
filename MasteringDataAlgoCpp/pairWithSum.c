/* Find out a pair of number that adds up to k */


#include <stdio.h>

/* Time O(n^2) */
void firstMethod(int *arr, int k){
  for (int i = 0; i < 9 ; i++) {
    for (int j = i+1; j < 10 ; j++) {
      if (arr[i] + arr[j] == k) {
	printf("%d+%d = %d\n", arr[i],arr[j],k);
      }
    }
  }
}


/* Hashing, Hash size = 16 because largest number is 16 */
/* Time O(n) */
void secondMethod(int *arr, int k){
  int hash[17] = {0};
  int temp;
  
  for (int i = 0; i < 10 ; i++) {
    temp = k-arr[i];
    if (hash[temp] != 0 && temp >= 0 && temp < 17) {
      printf("We have a pair\n");
      printf("%d + %d = %d\n", arr[i], k-arr[i], k);
    }
    hash[arr[i]]++; 		/* increment the current element in Hash */
  }
}



int main(){
  int a[10] = {6,3,8,10,16,7,5,2,9,14};
  /* firstMethod(a, 10); */
  secondMethod(a, 10);
  return 0;
}
