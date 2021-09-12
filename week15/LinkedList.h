#ifndef LINKED_LIST__H
#define LINKED_LIST__H

#include <iostream>
#include <sstream>

//forward class declaration
template <class T>
class List;

template <class T>
class LinkNode{
  friend class List<T>;
 public:
  LinkNode(){next = 0; prev = 0; data = 0;}
  ~LinkNode(){if(data){delete data; data = 0;}}
 private:
  T *data;
  LinkNode *next;
  LinkNode *prev;
};

template <class T>
class List{
 public:
  List(){head = 0; tail = 0;}
  ~List();
  void insertFront(T &);
  void insertRear(T &);
  void removeAll(T &);
  T removeRear();
  T removeFront();
  std::string toString();
  int getSize();
 private:
  LinkNode<T> *head;
  LinkNode<T> *tail;
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
void List<T>::insertFront(T &d){
  LinkNode<T> *link = new LinkNode<T>();
  T *nd = new T();
  *nd = d;
  link -> data = nd;

  if(head == 0){
    head = link;
    tail = link;
    return;
  }

  link -> next = head;
  head -> prev = link;
  head = link;
}

template <class T>
void List<T>::insertRear(T &d){
  LinkNode<T> *link = new LinkNode<T>();
  T *nd = new T();
  *nd = d;
  link -> data = nd;
  if(head == 0){
    head = link;
    tail = link;
    return;
  }
  link -> prev = tail;
  tail -> next = link;
  tail = link;
}

template <class T>
void List<T>::removeAll(T &d){
  LinkNode<T> *temp = head;

  if(!head) return;
  if(*(head -> data) == d){
    head = head -> next;
    delete temp -> data; temp -> data = 0;
    delete temp;
    return;
  }

  temp = head -> next;
  LinkNode<T> *prev = head;
  while(temp){
    if(*(temp -> data) == d){
      prev -> next = temp -> next;
      delete temp -> data; temp -> data = 0;
      delete temp;
      return;
    }
  }
}

template <class T>
int List<T>::getSize(){
  int count = 0;
  LinkNode<T> *temp = head;
  while(temp){
    count++;
    temp = temp -> next;
  }
  return count;
}

template <class T>
std::string List<T>::toString(){
  std::stringstream sstr;
  sstr << "{";
  std::string seperator = "";
  LinkNode<T> *temp = head;
  while(temp){
    sstr << seperator << *(temp -> data);
    temp = temp -> next;
    seperator = ", ";
  }
  sstr << "}";
  return sstr.str();
}

template <class T>
T List<T>::removeFront(){
  if(head == 0) return 0;
  T *temp = 0;
  T output;

  temp = head -> data;
  head -> data = 0;

  if(head == tail){
    delete head; head = 0; tail = 0;
    output = *temp;
    delete temp; temp = 0;
    return output;
  }

  LinkNode<T> *link = head;
  head -> next -> prev = 0;
  head = head -> next;
  delete link;
  output = *temp;
  delete temp; temp = 0;
  return output;
}

template <class T>
T List<T>::removeRear(){
  if(tail == 0) return 0;
  T *temp = 0;
  T output;

  temp = tail -> data;
  tail -> data = 0;

  if(head == tail){
    delete tail; tail = 0; head = 0;
    output = *temp;
    delete temp; temp = 0;
    return output;
  }

  LinkNode<T> *link = tail;
  tail -> prev -> next = 0;
  tail = tail -> prev;
  delete link;
  output = *temp;
  delete temp; temp = 0;
  return output;
}

#endif