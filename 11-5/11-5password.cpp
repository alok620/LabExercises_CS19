#include <iostream>
#include <cctype>
using std::string;

namespace{
  string password;
  bool isValid(){
    if(password.size() >= 8){
      for(unsigned i = 0; i < password.size(); i++){
        if(!std::isalpha(password[i])){
          return true;
        }
      }
    }
    return false;
  }
}

namespace Authenticate{
  void inputPassword(){
    do{
      std::cout << "Enter your password (at least 8 characters "
           << "and at least one non-letter)" << std::endl;
      std::cin >> password;
    } while(!isValid());
  }
  string getPassword(){
    return password;
  }
}