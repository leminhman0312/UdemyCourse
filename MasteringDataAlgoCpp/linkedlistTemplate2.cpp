#include <iostream>

template<class T>
class Linked_List
{
  struct Node
  {
    T data;
    Node* next;
  };
};





template<class T>
class Node
{
public:
  T data;
  Node<T> *next;
};

template<class T>
class LinkedList
{
private:
  Node<T> *first;
public:
  LinkedList(){first = NULL;}; 	// constructor
  LinkedList(T A[], int n); 	// constructor

  // FUNCTIONS
  void Display();
};

// Display
template<class T>
void LinkedList<T>::Display(){
  Node<T> *p = first;

  while (p != NULL) {
    std::cout << p->data << " ";
    p = p->next;
  }
  std::cout << std::endl;

}

// Create a linkedlist
template<class T>
LinkedList<T>::LinkedList(T A[], int n){
  Node <T> *last, *t;
  int i = 0;

  first = new Node<T>;
  first->data = A[0];
  first->next=NULL;
  last = first;

  for (i = 1; i < n ; i++) {
    t = new Node<T>;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

int main(){


  char A[] = {'a','b','c'};
  LinkedList<char> l(A,3);
  l.Display();

  
  return 0;
}



