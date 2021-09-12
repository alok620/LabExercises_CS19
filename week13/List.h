#ifndef LIST__H
#define LIST__H

#include <iostream>

class List{
 public:
  List() {head = 0;}
  ~List();
  void insert(int);
  void searchAndDelete(int);
  void insertRear(int);
  void print(); //print all
 private:
  LinkNode *head;
};

#endif