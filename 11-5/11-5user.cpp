#include <iostream>
using std::string;

namespace{
  string username;
  bool isValid(){
    if(username.size() == 8){
      return true;
    }
    return false;
  }
}

namespace Authenticate{
  
  void inputUserName(){
    do{
      std::cout << "Enter your username (8 letters only)" << std::endl;
      std::cin >> username;
    } while(!isValid());
  }
  string getUserName(){
    return username;
  }
}