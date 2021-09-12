#include <iostream>
#include "Security.h"

int Security::validate(std::string username, std::string password){
  if(username == "abbott" && password == "monday") return 1;
  if(username == "costello" && password == "tuesday") return 2;
  return 0;
}