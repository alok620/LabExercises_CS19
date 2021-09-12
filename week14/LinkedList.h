#ifndef LINKED_LIST__H
#define LINKED_LIST__H

#include <iostream>

//forward class declaration
template <class T>
class List;

template <class T>
class LinkNode{
  friend class List<T>;
 public:
  LinkNode(){next = 0; data = 0;}
  ~LinkNode(){if(data){delete data; data = 0;}}
 private:
  T *data;
  LinkNode *next;
 };

template <class T>
class List{
 public:
  List(){head = 0;}
  ~List();
  void insert(T *);
  void remove(T *);
  //void print();
 private:
  LinkNode<T> *head;
};

template <class T>
List<T>::~List(){
  LinkNode<T> *temp = head;

  while(head){
    temp = head;
    head = head -> next;
    if(temp -> data){
      delete temp -> data; temp -> data = 0;
    }
    delete temp;
  }
}

template <class T>
void List<T>::insert(T *d){
  LinkNode<T> *link = new LinkNode<T>();
  T *nd = new T();
  *nd = *d;
  head = link;
  link -> data = nd;
}

template <class T>
void List<T>::remove(T *d){
  LinkNode<T> *temp = head;

  if(!head) return;
  if(*(head -> data) == *d){
    head = head -> next;
    delete temp -> data; temp -> data = 0;
    delete temp;
    return;
  }

  temp = head -> next;
  LinkNode<T> *prev = head;
  while(temp){
    if(*(temp -> data == *d)){
      prev -> next = temp -> next;
      delete temp -> data; temp -> data = 0;
      delete temp;
      return;
    }
  }
}
/*
template <class T>
void List<T>::print(){
  LinkNode<T> *temp = head;
  while(temp){
    std::cout << temp -> data << std::endl;
  }
}
*/

#endif