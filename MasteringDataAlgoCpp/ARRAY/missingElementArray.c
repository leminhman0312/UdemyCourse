#include <stdio.h>
#include <stdlib.h>


/* ONE Missing element in sorted array */
/* Find sum of all number */
void iterSortedMissingNatural(int *arr){
  int sum;
  int s;
  for (int i = 0; i < 11 ; i++) {
    sum += *(arr+i);
  }
  
  s = (12*(12+1))/2;
  printf("%d\n", sum);
  printf("%d\n", s);
  printf("The missing element is %d\n", s-sum);
}


/* if no natural number */
void iterSortedNoNatural(int *arr){
  int diff, low;
  int n = 11;
  low = *arr;
  diff = low - 0;

  for (int i = 0; i < n ; i++) {
    if (*(arr+i)-i != diff) {
      printf("Missing element is: %d\n", i+diff);
      break;
    }
  }
}


/* MULTIPLE missing elements in an array */
void iterSortedMultiple(int *arr){
  int diff, low;
  low = *arr;
  diff = low-0;
  for (int i = 0; i < 11 ; i++) {
    /* if (*(arr+i)-i != diff) { */
    /*   while (diff < *(arr+i)-i) { */
    /* 	printf("%d\n", i+diff); */
    /* 	diff++; */
    /*   } */
    if (arr[i]-i != diff) {
      while (diff < arr[i]-i) {
	printf("%d\n", i+diff);
	diff++;
      }
    }
  }
}


/* Missing element in unsorted array */
void hashArrayMultiple(int *arr){
  int low, high;
  low = 1;
  high = 12;
  int harr[12] = {0};

  /* scan arr and increment harr */
  for (int i = 0; i < 10 ; i++) {
    harr[arr[i]]++;
  }

  /* scan harr for 0 */
  for (int i = low; i <= high ; i++) {
    if (harr[i] == 0) {
      printf("%d\n", i);
    }
  }
 
}
 


int main(){

  int arr[10] = {3,7,4,9,12,6,1,11,2,10};
  hashArrayMultiple(arr);
  return 0;
}

