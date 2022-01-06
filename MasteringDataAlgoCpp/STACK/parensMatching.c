#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char data;
  struct Node *next;
}*top = NULL;			/* making top pointer to  be global */

void push(char x){
  struct Node *t;
  t = (struct Node*)malloc(sizeof(struct Node));

  /* check if stack is full */
  if (t == NULL) {
    printf("stack is full\n");
  }
  else {
    t->data = x;
    t->next = top;
    top = t;
  }

}


char pop(){
  char x = -1;
  struct Node *t;
  if (top == NULL) {
    printf("stack is empty\n");
  }
  else {
    t = top;
    top = top->next;
    x = t->data;
    free(t);
  }
  return x;
}

void display(){
  struct Node *p;
  p = top;
  while (p != NULL) {
    printf("%d \n", p->data);
    p = p->next;
  }
  printf("\n");
}


int isBalanced(char *exp){
  int i;
  /* loop through the string */
  for (i = 0; exp[i] != '\0' ; i++) {
    
    /* check if OPEN paren */
    if (exp[i] == '(') {
      push(exp[i]);		/* push to stack */
    }
    /* check if CLOSE paren */
    else if (exp[i] == ')') {

      /* check if stack is empty */
      if (top == NULL) {
	return 0;		/* return 0 right away */
      }

      /* if not, pop out of stack */
      pop();
    }
  }
  if (top == NULL) {
    return 1;
  }
  else {
    return 0;
  }

}




int main(){
  char *exp = "((a+b)*(c-d)) ";
  
  

  printf("%d ", isBalanced(exp));
  return 0;
}
