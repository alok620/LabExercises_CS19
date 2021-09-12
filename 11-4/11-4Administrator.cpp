#include <iostream>
//#include "Security.h"
#include "Administrator.h"

bool Administrator::Login(std::string username, std::string password){
      if(Security::validate(username, password) == 2){
        return true;
      }
      return false;
    }