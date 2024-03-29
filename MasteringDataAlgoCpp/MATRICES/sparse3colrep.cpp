#include <iostream>
using namespace std;

class Element
{
public:
  int i;
  int j;
  int x;
};


class Sparse
{
private:
  int m;
  int n;
  int num;
  Element *ele;
public:
  // constructor
  Sparse(int m, int n, int num){
    this->m=m;
    this->n=n;
    this->num=num;
    ele=new Element[this->num];
  }

  // destructor
  ~Sparse(){
    delete [] ele;
  }


  Sparse operator+(Sparse &s);
  
  // extraction operator 
  friend istream & operator >> (istream &is, Sparse &s);

  // insertion operator
  friend ostream & operator << (ostream &os, Sparse &s);
  
};
  
Sparse Sparse::operator+(Sparse &s){
  int i,j,k;
  if (m != s.m || n!= s.n) {
    return Sparse(0,0,0);
  }
  Sparse *sum = new Sparse(m,n,num+s.num);

  i = j = k = 0;
  while (i < num && j < s.num) {
    
    if (ele[i].i < s.ele[j].i) {
      sum->ele[k] = ele[i];
      k++;
      i++;
    }
    else if (ele[i].i > s.ele[j].i){
      sum->ele[k] = s.ele[j];
      k++;
      j++;
    }
    else {
      
      if (ele[i].j < s.ele[j].j) {
	sum->ele[k] = ele[i];
	k++;
	i++;
      }
      else if (ele[i].j > s.ele[j].j) {
	sum->ele[k] = s.ele[j];
	k++;
	j++;
      }
      else {
	sum->ele[k] = ele[i];
	sum->ele[k].x = ele[i].x + s.ele[j].x;
	k++;
	i++;
	j++;
      }
    }
  }

  for (; i < num ; i++) {
    sum->ele[k] = ele[i];
    k++;
  }


  for (; j < s.num ; j++) {
    sum->ele[k] = s.ele[j];
    k++;
  }

  sum->num = k;
  return *sum;
  
}


istream & operator >> (istream &is, Sparse &s){
  std::cout << "Enter non zero elements\n";
  for (int i = 0; i < s.num ; i++) {
    std::cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
  }
  return is;
}

ostream & operator << (ostream &os, Sparse &s){
  int k = 0;
  for (int i = 0; i < s.m ; i++) {
    for (int j = 0; j < s.n ; j++) {
      if (s.ele[k].i == i && s.ele[k].j == j) {
	std::cout << s.ele[k].x << " ";
	k++;
      }
      else {
	std::cout << "0 ";
      }
    }
    std::cout << "\n";
  }
  return os;
}
  




int main(){

  Sparse s1(5,5,5);
  Sparse s2(5,5,5);
  
  cin >> s1;
  cin >> s2;
  cout << "First matrix\n" << s1;
  cout << "Second matrix\n " << s2;

  Sparse sum = s1 + s2;
  cout << "Sum matrix\n" << sum;

  return 0;
}
