#include <iostream>

class Diagonal
{
private:
  int n;
  int *A;
public:
  // constructor
  Diagonal(int n){
    this->n = n;
    A = new int[n];
  }
  void setDiag(int i, int j, int x);
  int getDiag(int i, int j);
  void display();
  // destructor
  ~Diagonal();
};


void Diagonal::setDiag(int i, int j, int x){
  if (i == j) {
    A[i-1] = x;
  }
}

int Diagonal::getDiag(int i, int j){
  if (i == j) {
    return A[i-1];
  }
  else {
    return 0;
  }
}

void Diagonal::display(){
  for (int i = 0; i < n ; i++) {
    for (int j = 0; j < n ; j++) {
      if (i == j) {
	std::cout << A[i] << " ";
      }
      else {
	std::cout << "0 ";
      }
    }
    std::cout << "\n";
  }
}

Diagonal::~Diagonal(){
  delete []A;
}

int main(){
  Diagonal diag(4);
  diag.setDiag(1, 1, 5);
  diag.setDiag(2, 2, 8);
  diag.setDiag(3, 3, 9);
  diag.setDiag(4, 4, 12);
  diag.display();
  
    
  return 0;
}


