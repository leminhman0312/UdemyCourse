#include <iostream>

class Node
{
public:
  int data;
  Node *next;
};

class LinkedList
{
private:
  Node *first;
public:
  LinkedList(){first = NULL;}; 	// constructor
  LinkedList(int A[], int n); 	// constructor
  ~LinkedList(); 		// destructor


  // FUNCTIONS
  void Display();
  void Insert(int index, int x);
  int Delete(int index);
  int Length();

  
};


// Create a linkedlist
LinkedList::LinkedList(int A[], int n){
  Node *last, *t;
  int i = 0;

  first = new Node;
  first->data = A[0];
  first->next=NULL;
  last = first;

  for (i = 1; i < n ; i++) {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

// Destructor, delete entire linkedlist
LinkedList::~LinkedList(){
  Node *p = first;
  while (first != NULL) {
    first = first->next;
    delete p;
    p = first;
  }
}

// Display
void LinkedList::Display(){
  Node *p = first;

  while (p != NULL) {
    std::cout << p->data << " ";
    p = p->next;
  }
  std::cout << std::endl;

}

// Get the length
int LinkedList::Length(){
  Node *p = first;
  int len = 0;

  while (p != NULL) {
    len++;
    p =  p->next;
  }
  return len;
}

// Insert element
void LinkedList::Insert(int index, int x){
  Node *t, *p = first;

  // check if index is invalid
  if (index < 0 || index > Length()) {
    return;
  }

  t = new Node;
  t->data = x;
  t->next = NULL;

  // Insert at the first node
  if (index == 0) {
    t->next = first;
    first = t;
  }
  else {
    // Loop to find pointer BEFORE the position that we want to replace
    for (int i = 0; i < index-1 ; i++) {
      p = p->next;
    }
    t->next = p->next; 		// points to the next node
    p->next = t;		// previous node points to the new t node

  }
}



int LinkedList::Delete(int index){
  Node *p, *q = NULL;
  int x = -1;

  if (index < 1 || index > Length()) {
    return -1;
  }
  if (index == 1) {
    p = first;
    first=first->next;
    x = p->data;
    delete p;
  }
  else {
    p = first;
    for (int i = 0; i < index-1 ; i++) {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    delete p;
  }
  return x;
}

int main(){

  // Note: count linkedlist as 1,2,3,4,5 not 0,1,2,3,4.
  int A[] = {1,2,3,4,5};
  LinkedList l(A,5);
  l.Delete(3);
  l.Display();

  
  return 0;
}
