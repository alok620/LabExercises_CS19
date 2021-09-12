#ifndef LINK_NODE__H
#define LINK_NODE__H

#include <iostream>

class LinkNode{
  friend class List;
 public:
  LinkNode() {next = 0; data = 0;}
  //~LinkNode() {if(data){delete data; data = 0;}}
 private:
 LinkNode *next; //"SRO"
 int data;
};

#endif