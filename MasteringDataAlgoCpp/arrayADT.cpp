#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Array
{
private:
  int *A; 		       
  int size;
  int length;
  void swap(int *x, int *y);
public:
  // non parametrized constructor
  Array(){
    size=10;
    length=0;
    A = new int[size];
  }
  // parametrized constructor
  Array(int sz){
    size=sz;
    length=0;
    A = new int[size];
  }

  // Destructor
  ~Array(){
    delete []A;
  }

  // Function prototype
  void Display();
  void Append(int x);
  void Insert(int index, int x);
  int Delete(int index);
  void InsertSorted(int x);
  int LinearSearch(int key);
  int ImpLinearSearch(int key);
  int BinarySearch(int key);
  // int BinarySearchRecursive( int a[], int l, int h, int key);
  int Get(int index);
  void Set(int index, int x);
  int Max();
  int Min();
  int Sum();
  float Avg();
  void Reverse();
  void Reverse2();
  void LeftShift();
  void LeftRotate();
  void RightShift();
  void RightRotate();
  void InsertSorted();
  int isSorted();
  void Rearrange();
  Array* Merge(Array arr2);
  Array* Union(Array arr2);
  Array* Intersection(Array arr2);
  Array* Difference(Array arr2);
  void setLength(int l);
  int getLength();
};


void Array::setLength(int l){
  length=l;
}

int Array::getLength(){
  return length;
}

void Array::Display(){
  int i;
  printf("\nElements are:\n");

  for (i = 0; i < length ; i++) {
    printf("%d\n", A[i]);
  }
}

void Array::Append(int x){
  if (length < size) {
    A[length++] = x;
  }
}


void Array::Insert(int index, int x){
  int i;
  if (index >= 0 && index <= length) {
    for (i = length; i > index  ; i--) {
      A[i] = A[i-1];
    }
    A[index] = x;
    length++;
  }
}



int Array::Delete(int index){
  int x = 0;
  int i;
  if (index >= 0 && index <= length-1) {
    x = A[index];
    for (i = index; i < length-1 ; i++) {
      A[i] = A[i+1];
    }
    length--;
    return x;
  }
  return 0;
}

void Array::swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}


int Array::LinearSearch(int key){
  int i;
  for (i = 0; i < length ; i++) {
    if (key == A[i]) {
      return i;
    }
  }
  return -1;
}

int Array::ImpLinearSearch(int key){
  int i;
  for (i = 0; i < length ; i++) {
    if (key == A[i]) {
      swap(&A[i], &A[0]);
      return i;
    }
  }
  return -1;
}


int Array::BinarySearch(int key){
  int l, mid, h;
  l = 0;
  h = length-1;
  while (l <= h) {
    mid = (l+h)/2;
    if (key == A[mid]) {
      return mid;
    }
    else if (key < A[mid]) {
      h = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  
  return -1;
}


// int BinarySearchRecursive(int a[], int l, int h, int key){
//   int mid;
//   if (l <= h) {
//     mid = (l + h)/2;
//     if (key == a[mid]) {
//       return mid;
//     }
//     else if (key < a[mid]) {
//       return BinarySearchRecursive(a, l, mid-1, key);
//     }
//     else {
//       return BinarySearchRecursive(a, mid+1, h, key);
//     }
//   }
//     return -1;
// }


int Array::Get(int index){
  if (index >= 0 && index < length){
    return A[index];
  }
  return -1;
}


void Array::Set(int index, int x){
  if (index >= 0 && index < length){
    A[index] = x;
  }
}

int Array::Max(){
  int max=A[0];
  for (int i = 1; i < length ; i++) {
    if (A[i] > max) {
      max = A[i];
    }
  }
  return max;
}


int Array::Min(){
  int min=A[0];
  for (int i = 1; i < length ; i++) {
    if (A[i] < min) {
      min = A[i];
    }
  }
  return min;
}


int Array::Sum(){
  int s = 0;
  for (int i = 0; i < length ; i++) {
    s = s + A[i];
  }
  return s;
}

float Array::Avg(){
  return (float)Sum()/length;
}


void Array::Reverse(){
  int *B;
  int i, j;

  B = (int*)malloc(sizeof(int) * length);

  /* Put reverse  */
  for (i = length-1, j = 0; i >= 0  ; i--, j++) {
    B[j] = A[i];
  }
  /* Put B to A */
  for (i = 0; i < length ; i++) {
    A[i] = B[i];
  }
}

void Array::Reverse2(){
  int i, j;
  for (i = 0,j = length-1 ; i < j ; i++,j--) {
    swap(&A[i], &A[j]);
  }
}


void Array::LeftShift(){
  int i;
  for (i = 0; i < length-1 ; i++) {
    A[i] = A[i+1];
  }
  A[length-1] = 0;
}

void Array::LeftRotate(){
  int i;
  int temp = A[0];
  for (i = 0; i < length-1 ; i++) {
    A[i] = A[i+1];
  }
  A[length-1] = temp;
}

void Array::RightShift(){
  int i;
  for (i = length-1; i >= 1 ; i--) {
    A[i] = A[i-1];
  }
  A[0] = 0;
}


void Array::RightRotate(){
  int i;
  int temp = A[length-1];
  for (i = length-1; i >= 1 ; i--) {
    A[i] = A[i-1];
  }
  A[0] = temp;
}

void Array::InsertSorted(int x){

  int i = length-1;
  if (length == size) {
    return;
  }
  while (i >= 0 && A[i] > x) {
    A[i+1] = A[i];
    i--;
  }
  A[i+1] = x;
  length++;
}


int Array::isSorted(){
  int i;
  for (i = 0; i < length-1 ; i++) {
    if (A[i] > A[i+1]) {
      return 0;			/* false */
    }
  }
  return 1;			/* true */
}


void Array::Rearrange(){
  int i, j;
  i = 0;
  j = length-1;

  while (i < j) {
    while (A[i] < 0) {
      i++;
    }

    while (A[j] >= 0) {
      j--;
    }

    if (i < j) {
      swap(&A[i], &A[j]);
    }
  }
}


Array* Array::Merge(Array arr2){
  int i, j, k;
  i = j = k = 0;
  Array *arr3=new Array(length+arr2.length);

  while (i < length && j < arr2.length) {
    if (A[i] < arr2.A[j]) {
      arr3->A[k] = A[i];	/* put in new array */
      i++;			
      k++;
    }
    else {
      arr3->A[k] = arr2.A[j];	/* put in new array */
      j++;
      k++;
    }
  }

  while (i < length) {
    arr3->A[k] = A[i];
    i++;
    k++;
  }

  while (j < arr2.length) {
    arr3->A[k] = arr2.A[j];
    j++;
    k++;
  }
  
  arr3->length = length + arr2.length;
  return arr3;
}




Array* Array::Union(Array arr2){
  int i, j, k;
  i = j = k = 0;
  Array *arr3=new Array(length+arr2.length);

  while (i < length && j < arr2.length) {
    if (A[i] < arr2.A[j]) {
      arr3->A[k] = A[i];	/* put in new array */
      i++;			
      k++;
    }
    else if(arr2.A[j] < A[i]){
      arr3->A[k] = arr2.A[j];	/* put in new array */
      j++;
      k++;
    }
    else {
      arr3->A[k] = A[i];
      k++;
      i++;
      j++;
    }
  }

  while (i < length) {
    arr3->A[k] = A[i];
    i++;
    k++;
  }

  while (j < arr2.length) {
    arr3->A[k] = arr2.A[j];
    j++;
    k++;
  }
  
  arr3->length = k;

  return arr3;
}


Array* Array::Intersection(Array arr2){
  int i, j, k;
  i = j = k = 0;
  Array *arr3=new Array(length+arr2.length);

  while (i < length && j < arr2.length) {
    if (A[i] < arr2.A[j]) {
      i++;			
    }
    else if(arr2.A[j] < A[i]){
      j++;
    }
    else if(A[i] == arr2.A[j]){
      arr3->A[k] = A[i];
      k++;
      i++;
      j++;
    }
  }


  arr3->length = k;
  return arr3;
}



Array* Array::Difference(Array arr2){
  int i, j, k;
  i = j = k = 0;
  Array *arr3=new Array(length+arr2.length);

  while (i < length && j < arr2.length) {
    if (A[i] < arr2.A[j]) {
      arr3->A[k] = A[i];	/* put in new array */
      i++;			
      k++;
    }
    else if(arr2.A[j] < A[i]){
      j++;
    }
    else {
      i++;
      j++;
    }
  }

  while (i < length) {
    arr3->A[k] = A[i];
    i++;
    k++;
  }
  
  arr3->length = k;

  return arr3;
}


int main(){

  Array *arr1;
  int ch,sz;
  int index, x;
  
  cout << "Enter size of array\n";
  cin >> sz;
  arr1 = new Array(sz);
  arr1->setLength(0);
  // arr1->length = 0;

  do
    {
      cout << "Menu\n";
      cout << "1. Insert\n";
      cout << "2. Delete\n";
      cout << "3. Search\n";
      cout << "4. Sum\n";
      cout << "5. Display\n";
      cout << "6. Exit\n";

      cout<< "Enter your choice\n";
      cin >> ch;

      switch (ch) {
      case 1: {
	cout << "Enter an element and index\n";
	cin >> x >> index;
	arr1->Insert(index, x);
	break;
      }
      case 2: {
	cout << "Enter index\n";
	cin >> x;
	x = arr1->Delete(index);
	cout << "Deleted Element is " << x << "\n";
	break;
      }
      case 3: {
	cout << "Enter element to search\n";
	cin >> x;
	index=arr1->LinearSearch(x);
	cout << "Element index " << index << "\n";
	break;
      }
      case 4: {
	cout << "Sum is " <<  arr1->Sum() << "\n";
	break;
      }
      case 5: {
	arr1->Display();
      }
      }
    }while (ch<6);
  return 0;
}
