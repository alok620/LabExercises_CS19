#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>


int main(){
  int N = 0;
  std::cout << "Enter N: ";
  std::cin >> N;
  bool set[N];
  for(int i = 2; i < N; i++){
    set[i] = true;
  }
  set[0] = false;
  set[1] = false;
  double bound = std::sqrt(N);

  for(int i = 2; i < bound; i++){
    if(set[i]){
      for(int j = 2; j < N; j++){
        if(i*j < N){
          set[i*j] = false;
        }
      }
    }
  }


  for(int i = 0; i < N; i++){
    if(set[i]){
      std::cout << i << ", ";
    }
  }

  std::cout << "\n";

  return 0;
}