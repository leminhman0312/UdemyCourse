#include <stdio.h>


void printChar(char *arr){
  for (int i = 0; arr[i] != '\0'  ; i++) {
    printf("%c ", arr[i]);
  }
}

void printInt(int *arr){
  for (int i = 0; i < 4  ; i++) {
    printf("%d ", arr[i]);
  }
}

void perm(char s[], int k){
  static int A[10] = {0};
  static char Res[10];
  int i;
  if (s[k] == '\0') {
    Res[k] = '\0';		/* marked the last elements in Res to be \0 for string */
    printf("Answer = %s\n", Res);
  }
  else {
    for (i = 0; s[i] != '\0'  ; i++) {

      printf("\ni = %d\tk = %d\n", i, k);
      
      /* check if alphabet available or not */
      if (A[i] == 0) {
	printf("Alphabet available\n");
	Res[k] = s[i];

	printf("Set Res[%d] = s[%d]\n", k, i);
	printf("Res[] = \n");
	printChar(Res);

	printf("\n");

	
	A[i] = 1;		/* marked as 1 alphabet NOT available */
	printf("Marked A[%d] = 1\n", i);
	printf("A[] = \n");
	printInt(A);

	printf("\n------------------------------------------------------------------------------\n");
	printf("\nCalling perm(s,%d)\n", k+1);
	perm(s,k+1);
	A[i] = 0;		/* marked as 0 for RETURNING call */
	/* printf("\ni = %d\tk = %d\n", i, k); */
	printf("Marked A[%d] = 0\n", i);
	printf("A[] = \n");
	printInt(A);
      }
      else {
	printf("Alphabet NOT available\n");
      }
    }
  }
}






int main(){
  char s[] = "ABC";
  printf("Calling perm(s,0)\t\tk = 0\n");
  perm(s,0);
  return 0;
}
