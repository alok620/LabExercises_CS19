#ifndef QUEUE__H
#define QUEUE__H

#include <iostream>
#include "LinkedList.h"

template <class T>
class Queue : public List<T>{
 public:
  void enque(T &d) {List<T>::insertRear(d);}
  T dequeue() {return List<T>::removeFront();}
};

#endif