#include <iostream>
#include "LinkNode.h"
#include "List.h"

List::~List(){
  LinkNode *temp = head;
  while(head){
    temp = head;
    head = head -> next;
    delete temp; temp = 0;
  }
}

void List::print(){
  LinkNode *temp = head;
  while(temp != 0){
    std::cout << temp -> data << std::endl;
    temp = temp -> next;
  }
}

void List::insert(int d){
  LinkNode *temp = new LinkNode();
  temp -> data = d;
  temp -> next = head;
  head = temp;
}

void List::insertRear(int d){
  if(!head){
    insert(d);
    return;
  }
  LinkNode *temp = head -> next;
  LinkNode *prev = head;
  while(temp){
    prev = temp;
    temp -> next;
  }
  //reuse temp since it has served orig purpose
  temp = new LinkNode();
  temp -> data = d;
  prev -> next = temp;
}

void List::searchAndDelete(int d){
  LinkNode *prev;
  if(head -> data == d){
    prev = head;
    head = prev -> next;
    delete prev; prev = 0;
  }
  prev = head;
  LinkNode *temp = head -> next;
  while(temp){
    if(temp -> data == d){
      prev -> next = temp -> next;
      delete temp;
      temp = prev -> next;
    } else {
      prev = temp;
      temp = temp -> next;
    }
  }
}