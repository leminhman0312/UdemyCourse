#include <stdio.h>

int palindromeSingle(char *A){
    int i, j;
    i = 0;
    j = 0;

    char left, right;

    
    /* Find out stopping  index */
    for (j = 0; A[j] != '\0'  ; j++) {
    }
    j = j-1;
    

    while (i != j){
      left = A[i];
      right = A[j];
   
      if (left == right) {
	i++;
	j--;
      }
      else {
	break;
	return -1;
      }
    }

    /* if (i == j) { */
    /*   printf("It is a palindrome\n"); */
    /* }else { */
    /*   printf("It is not a palindrome\n"); */
    /* } */

    return 1;

}


int main(){
    char A[] = "abba";
    int result = palindromeSingle(A);

    if (result == 1) {
      printf("It is a palindrome\n");
    }else {
      printf("It is NOT a palindrome\n");
    }

    
    return 0;
}
