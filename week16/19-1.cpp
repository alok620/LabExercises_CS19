#include <iostream>
#include <array>
#include <algorithm>
#include <sstream>

void print(double arr[]);

int main(){
  double arr[10];
  std::cout << "Enter 10 doubles: ";
  for(int i = 0; i < 10; i++){
    std::cin >> arr[i];
  }

  std::sort(arr, arr + 10);
  print(arr);

  return 0;
}

void print(double arr[]){
  std::string sep = "";

  for(int i = 0; i < 10; i++){
    std::cout << sep << arr[i];
    sep = ", ";
  }
  std::cout << std::endl;
}