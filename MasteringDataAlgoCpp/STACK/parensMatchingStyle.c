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


int match(char a, char b){

  /* check PARENS */
  if (a == '(' && b == ')') {
    return 1;
  }
  if (a == '[' && b == ']') {
    return 1;
  }
  if (a == '{' && b == '}') {
    return 1;
  }

  /* check ASCII */
  /* int diff = abs(b-a); */
  /* if (diff < 100) { */
  /*   if (diff == 1) { */
  /*     return 1; */
  /*   } */
  /*   if (diff == 2) { */
  /*     return 1; */
  /*   } */
  /* } */
  /* else { */
  /*   if (diff == 2) { */
  /*     return 1; */
  /*   } */
  /* } */
  

  return 0;
  
}

int isBalanced(char *exp){
  int i;
  signed char open_char, close_char;
  /* loop through the string */
  for (i = 0; exp[i] != '\0' ; i++) {
    /* check if OPEN paren */
    if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
      push(exp[i]);		/* push to stack */
    }

    /* check if CLOSE paren */
    else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
      close_char = exp[i];
      
      /* check if stack is empty */
      if (top == NULL) {
	return 0;		/* return 0 right away */
      }

      /* if not, pop out of stack */
      open_char = pop();
      if (match(open_char, close_char) == 0) {
	return 0;
      }
    }

  }


  /* terminating  */
  if (top == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}

int main(){
  char *exp = "()[a-b]())";
  for (int i = 0; exp[i] != '\0'  ; i++) {
     printf("%c", *(exp+i));
  }


  if (isBalanced(exp) == 1) {
    printf("\nTRUE\n");
  }
  else {
    printf("\nFALSE\n");
  }

  
  return 0;
}
