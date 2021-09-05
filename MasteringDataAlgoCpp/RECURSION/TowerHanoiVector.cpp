#include <iostream>
#include <tuple>
#include <vector>

std::tuple<int, int> TOH(int n, int A, int B, int C){
  if (n > 0) {
    TOH(n-1,A,C,B);
    return std::make_tuple(A,C); 
    TOH(n-1,B, A, C);
  }
  return std::make_tuple(0,0);
}



int main(){
  std::vector<int> a, b, c;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);

  TOH(3,1,2,3);
  
  return 0;
}
