#include <iostream>

template<class T>
class Array
{
private:
  T *A;
  int size;
  int length;
public:
  Array()			// constructor
  {
    size=10;
    length=0;
    A=new T[10];
  }

  Array(int sz)			// parametrized constructor
  {
    size = sz;
    length = 0;
    A = new T[size];
  }

  ~Array()			// destructor
  {
    delete []A;
  }

  void Display();
  void Insert(int index, T x);
  T Delete(int index);
};

template<class T>
void Array<T>::Display(){
  std::cout << "Elements are" << "\n";
  for (int i = 0; i < length ; i++) {
    std::cout << A[i] << "\t";
  }
  std::cout << " ";
}

template<class T>
void Array<T>::Insert(int index, T x){

  if (index >= 0 && index <= length) {
    for (int i = length-1; i >= index  ; i--) {
      A[i+1] = A[i];
    }
    A[index] = x;
    length++;
  }

}

template<class T>
T Array<T>::Delete(int index){
  T x = 0;
  if (index >= 0 && index < length) {
    x = A[index];
    for (int i = index; i < length-1 ; i++) {
      A[i] = A[i+1];
    }
    length--;
   }
  return x;
}



int main(){
  
  Array<char> arr(10);
  arr.Insert(0, 'a');
  arr.Insert(1, 'b');
  arr.Insert(2, 'd');
  arr.Display();

  std::cout << "\nRemove element "  << arr.Delete(0) << "\n";
  arr.Display();


  return 0;
}
