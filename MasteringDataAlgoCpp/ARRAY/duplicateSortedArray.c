/* find duplicate in sorted array */
#include <stdio.h>
#include <stdlib.h>

void duplicateSorted(int *arr){
  int lastDuplicate = 0;
  for (int i = 0; i < 10 ; i++) {
    if (arr[i] == arr[i+1] && arr[i] != lastDuplicate) {
      printf("%d\n", arr[i]);
      lastDuplicate = arr[i];
    }
  }
}

void countDuplicateSorted(int *arr){
  int j = 0;
  for (int i = 0; i < 9 ; i++) {
    if (arr[i] == arr[i+1]) {
      j = i;
      while (arr[j] == arr[i]) {
	j++;
      }
      printf("%d is appearing %d times\n", arr[i], j-i);
      i = j-1;
    }
  }
}

void duplicateHash(int *arr){
  int hash[21] = {0};
  for (int i = 0; i < 10 ; i++) {
    hash[arr[i]]++;
  }

  for (int i = 0; i <= 20 ; i++) {
    if (hash[i] > 1) {
      printf("%d appear %d times \n", i , hash[i]);
    }
  }
}


int main(){
  int a[10] = {3,6,8,8,10,12,15,15,15,20};
  duplicateHash(a);
  return 0;
}


