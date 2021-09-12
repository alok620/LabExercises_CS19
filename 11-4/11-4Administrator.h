#ifndef ADMINISTRATOR__H
#define ADMINISTRATOR__H

#include <iostream>
#include "Security.h"

class Administrator{
  public:
    static bool Login(std::string username, std::string login);
};


#endif