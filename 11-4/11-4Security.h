#ifndef SECURITY__H
#define SECURITY__H

#include <iostream>

class Security{
  public:
    static int validate(std::string username, std::string password);
};


#endif