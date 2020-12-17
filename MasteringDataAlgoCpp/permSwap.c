#include <stdio.h>

void swap(char *x, char *y){
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void printChar(char *arr){
  printf("Printing s: \n");
  for (int i = 0; arr[i] != '\0'  ; i++) {
    printf("%c", arr[i]);
  }
  printf("\n");
}



void perm2(char s[], int l, int h){
  int i;

  printf("LOW=%d\t\tHIGH=%d\n", l , h);

  
  if (l == h) {
    printf("RESULT:\t\t%s\n", s);
  }

  else {
    for (i = l; i <= h; i++) {
      printf("i = %d\n", i);
      printf("First swap s[%d] with s[%d]\n", l , i);
      swap(&s[l],&s[i]);
      printChar(s);
      printf("--------------------------------------------------------\n");
      printf("Calling perm2(s,%d,%d)\n", l+1, h );
      perm2(s,l+1,h);
      printf("Second swap s[%d] with s[%d]\n", l , i);
      swap(&s[l],&s[i]);
      printChar(s);
    }
  }
}

int main(){
  char s[] = "ABC";
  perm2(s,0,2);
  return 0;
}
