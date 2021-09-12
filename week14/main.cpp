#include <iostream>
#include "LinkedList.h"
using std::string;

int main(){
  List<string> *L = new List<string>();
  string *str1 = new string();
  *str1 = "hello";
  L->insert(str1);
  return 0;
}