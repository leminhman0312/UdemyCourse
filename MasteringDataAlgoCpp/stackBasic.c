
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int stack[256];
int count = 0;

void push(int x){
  stack[count] = x;
  count++;
}

int pop(){
  int result = stack[count-1];
  count--;
  return result;
}

int main(){
  push(1);
  push(2);
  push(3);
  push(5);

  for (int i = 0; i < 4 ; i++) {
    printf("%d\n", pop());
  }

  return 0;
}
