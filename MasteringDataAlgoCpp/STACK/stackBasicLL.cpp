#include <iostream>

class Node
{
public:
  int data;
  Node *next;
};


class Stack
{
private:
  Node *top;
public:
  Stack(){top=NULL;};
  void push(int x);
  int pop();
  void display();
};


void Stack::push(int x){
  Node *t = new Node;
  if (t == NULL) {
    std::cout << "Stack is full \n";
  }
  else {
    t->data = x;
    t->next = top;
    top = t;
  }
}

int Stack::pop(){
  int x = -1;
  if (top == NULL) {
    std::cout << "Stack is empty \n";
  }
  else {
    x = top->data;
    Node *t=top;
    top = top->next;
    delete t;
  }
  return x;
}


void Stack::display(){
  Node *p = top;
  while (p != NULL) {
    std::cout << p->data << " ";
    p = p->next;
  }
  std::cout << "\n";
}


int main(){
  Stack stk;
  stk.push(10);
  stk.push(20);
  stk.push(30);

  stk.display();
  std:: cout << stk.pop();
  return 0;
}


