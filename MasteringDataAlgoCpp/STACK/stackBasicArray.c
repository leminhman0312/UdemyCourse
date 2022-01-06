#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  int size;
  int top;
  int *S;
};


/* Allocate a stack with given size */
void create(struct Stack *st){
  printf("Enter size\n");
  scanf("%d", &st->size);
  st->top = -1;
  st->S = (int *)malloc(sizeof(st->size*sizeof(int)));
}



/* Display a stack */
void display(struct Stack st){
  int i;
  for (i = st.top; i >= 0  ; i--) {
    printf("%d\n", st.S[i]);
  }
  printf("\n");
}


void push(struct Stack *st, int x){
  /* check if stack is full */
  if (st->top == st->size-1) {
    printf("Stack OVERFLOW !\n");
  }

  /* insert a value if not */
  else {
    st->top++;			/* move the top pointer */
    st->S[st->top] = x;		/* array at the new top is X */
  }
}

int pop(struct Stack *st){
  int x = -1;

  /* check if stack is empty */
  if (st->top == -1) {
    printf("Stack UNDERFLOW !\n");
  }
  else {
    
    x = st->S[st->top];	/* take out the value */
    st->top--;		/* decrease the pointer */
  }
  return x;
}


/* Array index goes from bottom */
/* Stack position goes from top */
int peek (struct Stack st, int index){
  int x = -1;

  /* check if the position is valid or not */
  /* recall pos = top - index + 1 */
  if (st.top-index+1 < 0 ) {
    printf("Invalid position ! \n");
  }
  else {
    x = st.S[st.top-index+1];
  }
  return x;
}


/* check if stack empty */
int isEmpty(struct Stack st){
  if (st.top == -1) {
    return 1;
  }
  else {
    return 0;
  }
  
}

/* check if stack is full */
int isFull(struct Stack st){
  if (st.top == st.size-1) {
    return 1;
  }
  else {
    return 0;
  }
}

int stackTop(struct Stack st){
  if ( !isEmpty(st)) {
    return st.S[st.top];
  }else {
    return -1;
  }
}



int main(){
  struct Stack st;
  create(&st);
  printf("Pushin to stack\n");
  push(&st, 10);
  push(&st, 20);
  push(&st, 30);
  push(&st, 40);
  

  int peekPos = 3;
  printf("Peeking at position %d , we have %d \n", peekPos, peek(st,peekPos));

  printf("Displaying stack\n");
  display(st);


  printf("Checking if stack is full %d \n", isFull(st));
  
  
  return 0;
}
