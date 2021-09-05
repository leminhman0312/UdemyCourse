/* Find duplicates in unsorted array  */
#include <stdio.h>
#include <stdlib.h>


void duplicateUnsorted(int *arr){

  int count;
  
  for (int i = 0; i < 9 ; i++) {
    count = 1;
    if (arr[i] != -1) {
      
      for (int j = i+1; j < 10 ; j++) {
	if (arr[i] == arr[j]) {
	    count++;
	    arr[j] = -1;
	}
      }
    }
    if (count > 1) {
      printf("%d %d\n", arr[i], count);
    }

  }

}

void duplicatedHash(int *arr){
  int hash[9] = {0};
  /* put into hash  */
  for (int i = 0; i < 10 ; i++) {
    hash[arr[i]]++;
  }

  /* loop through hash */
  for (int i = 0; i < 9 ; i++) {
    if (hash[i] > 1) {
      printf("%d appear %d times \n", i , hash[i]);
    }
  }

}

int main(int argc, char *argv[]){
  int a[10] = {8,3,6,4,6,5,6,8,2,7};
  duplicatedHash(a);
  return 0;
}
