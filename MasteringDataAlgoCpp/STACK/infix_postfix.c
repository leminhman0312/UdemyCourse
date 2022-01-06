#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* declare a character stack */
struct Node
{
  char data;
  struct Node *next;
}*top=NULL;


/* push character x to stack */
void push(char x){
  struct Node *t;
  t=(struct Node*)malloc(sizeof(struct Node));

  if (t == NULL) {
    printf("Stack is full\n");
  }
  else {
    t->data = x;
    t->next = top;
    top = t;
  }
}

/* pop a character */
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

/* display the LL */
void display(){
  struct Node *p;
  p = top;
  while (p != NULL) {
    printf("%d\n", p->data);
    p = p->next;
  }
  printf("\n");
}

/* assign precedence to operator */
int pre(char x){
  if (x == '+' || x == '-') {
    return 1;
  }
  else if (x == '*' || x == '/') {
    return 2;
  }
  /* add more if more precedence.... */
  else {
    return 0;
  }
}

/* check if symbol is operand */
int isOperand(char x){

  /* if NOT operand */
  if (x == '+' || x == '-' || x == '*' || x == '/' ) {
    return 0;
  }

  /* if operand */
  return 1;
}


/* conversion */
char * InToPost(char *infix){
  int i = 0, j = 0;
  char *postfix;
  int len = strlen(infix);
  postfix = (char *)malloc(sizeof(char)*(len+2)); /* len + 1 because need '\0' for string, len + 2 because we added "#"  */

  while (infix[i] != '\0') {

    /* symbol is operand */
    if (isOperand(infix[i]) == 1) {

      /* copy operand to postfix */
      postfix[j] = infix[i];

      /* increase the counters */
      i++;
      j++;
    }

    /* symbol is NOT operand */
    else {

      /* compare precedence between the current infix and the stack's top */
      /* if higher, push current infix to stack */
      if (pre(infix[i])>pre(top->data)) {
	push(infix[i]);
	i++;
      }
      /* if smaller, pop current infix, add it to postfix */
      else {
	postfix[j] = pop();
	j++;
      }
    }
  }

  /* pull out remaining */
  while (top != NULL) {
    postfix[j] = pop();
    j++;
  }

  /* add a null character */
  postfix[j] = '\0';
  return postfix;
}



int main(){
  char *infix = "a+b*c-d/e";


  push('#');
  
  char *postfix=InToPost(infix);

  printf("%s\n", postfix);
  return 0;
}
