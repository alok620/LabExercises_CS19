#include <iostream>
#include "User.h"

bool User::Login(std::string username, std::string password){
if(Security::validate(username, password) == 1 ||
Security::validate(username, password) == 2){
  return true;
}
return false;

}