#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"

int main(){
  Stack<std::string> s;
  std::string one = "one";
  std::string two = "two";

  s.push(one);
  s.push(two);

  std::cout << s.toString() << std::endl;
  std::string temp = s.pop();
  std::cout << temp << std::endl;
}