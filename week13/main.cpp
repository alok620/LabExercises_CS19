#include <iostream>
#include "LinkNode.h"
#include "List.h"

int main(){
  List L;
  L.insert(7);
  L.insert(5);
  L.insert(7);
  L.insert(5);
  L.insert(7);
  L.print();
  L.searchAndDelete(7);
  std::cout << "Changed List:\n";
  L.print();
}