#include <iostream>
#include "Student.h"

using std::cout;
using std::endl;

int main(){
  Student stu = Student();
  stu.inputData();
  cout << endl;
  stu.printStudent();

  return 0;
}