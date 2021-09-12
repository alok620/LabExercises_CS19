#include <iostream>
#include "Student.h"

using std::cout;
using std::endl;
using std::string;
using std::cin;

Student::Student(){
  name = "";
  numClasses  =0;
  classList = NULL;
}
Student::~Student(){
  if(classList != NULL){
    delete [] classList;
  }
}

void Student::resetClasses(){
  if(classList != NULL){
    delete [] classList;
    classList = NULL;
  }
  numClasses = 0;
}

void Student::inputData(){
  resetClasses();
  cout << "Enter student name: ";
  std::getline(cin, name);
  cout << "Enter number of classes: ";
  cin >> numClasses;
  cin.ignore();
  if(numClasses > 0){
    classList = new string[numClasses];
    for(int i = 0; i < numClasses; i++){
      cout << "Enter class name (" << (i+1) << "/"
           << numClasses << "): ";
      std::getline(cin, classList[i]);
    }
  }
}

void Student::printStudent(){
  cout << "Student name: " << name << endl;
  cout << "Number of classes: " << numClasses << endl;
  for(int i = 0; i < numClasses; i++){
    cout << "Class " << (i+1) << ": " << classList[i] << endl;
  }
}

Student& Student::operator = (const Student& stuObject){
  resetClasses();
  name = stuObject.name;
  numClasses = stuObject.numClasses;
  if(numClasses > 0){
    classList = new string[numClasses];
    for(int i = 0; i < numClasses; i++){
      classList[i] = stuObject.classList[i];
    }
  }
  return *this;
}