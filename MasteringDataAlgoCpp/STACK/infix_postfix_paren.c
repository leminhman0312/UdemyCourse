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
  if (x == '+' || x == '-' || x == '*' || x == '/' ||
      x == '^' || x == '(' || x ==')'){
    return 0;
  }

  /* if operand */
  return 1;
}

int outPrecedence(char x){
  if (x == '+' || x == '-') {
    return 1;
  }
  if (x == '*' || x == '/') {
    return 3;
  }
  if (x == '^') {
    return 6;
  }
  if (x == '(') {
    return 7;
  }
  if (x == ')') {
    return 0;
  }
  return -1;
}

int inPrecedence(char x){
  if (x == '+' || x == '-') {
    return 2;
  }
  if (x == '*' || x == '/') {
    return 4;
  }
  if (x == '^') {
    return 5;
  }
  if (x == '(') {
    return 0;
  }
  return -1;
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

      if (top == NULL || outPrecedence(infix[i])> inPrecedence(top->data)) {
	push(infix[i]);
	i++;
      }
      else if (outPrecedence(infix[i]) == inPrecedence(top->data)) {
	pop();
      }
      else {
	postfix[j] = top->data;
	pop();
	j++;
      }
    }
  }

  /* pull out remaining */
  while (top != NULL && top->data != ')') {
    postfix[j] = top->data;
    j++;
    pop();
  }

  /* add a null character */
  postfix[j] = '\0';
  return postfix;
}



int main(){
  char *infix = "((a+b)*c)-d^e^f";


  push('#');
  
  char *postfix=InToPost(infix);

  printf("%s\n", postfix);
  return 0;
}
