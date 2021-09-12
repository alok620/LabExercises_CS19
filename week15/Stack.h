#ifndef STACK__H
#define STACK__H

#include <iostream>
#include "LinkedList.h"

template <class T>
class Stack : public List<T>{
 public:
  void push(T &d) {List<T>::insertFront(d);}
  T pop() {return List<T>::removeFront();}
};

#endif