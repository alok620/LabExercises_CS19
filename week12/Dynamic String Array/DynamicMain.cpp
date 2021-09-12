#include <iostream>
#include "DynamicStringArray.h"
using std::cout;
using std::endl;

int main(){
  DynamicStringArray dsa;
  dsa.addEntry("hello");
  cout << dsa.getEntry(0) << endl;

  return 0;
}