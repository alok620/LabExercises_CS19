#include <iostream>
#include "Security.h"
#include "User.h"
#include "Administrator.h"

int main() {
  std::string username, password;

  std::cout << "Enter username: ";
  std::cin >> username;
  std::cout << "Enter password: ";
  std::cin >> password;
  std::cout << "\n";
  if(Administrator::Login(username, password)){
    std::cout << "Administrator privileges granted\n";
  } else{
    std::cout << "Administrator privileges not granted\n";
  }
  if(User::Login(username, password)){
    std::cout << "Welcome user\n";
  } else{
    std::cout << "Access denied\n";
  }
  
  return 0;
}