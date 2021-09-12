#include <iostream>

int handShakes(int numPeople);

int main() {
  std::cout << handShakes(4) << "\n";
}

int handShakes(int numPeople){
  if(numPeople <= 1){
    return 0;
  }
  if(numPeople == 2){
    return 1;
  }

  return numPeople - 1 + handShakes(numPeople - 1);
}