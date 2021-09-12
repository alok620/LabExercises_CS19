#ifndef STUDENT__H
#define STUDENT__H

#include <iostream>
using std::string;

class Student{
 public:
  Student();
  ~Student();
  void inputData();
  void printStudent();
  void resetClasses();
  Student& operator = (const Student& stuObject);
 private:
  string name;
  int numClasses;
  string *classList;

};

#endif