#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

const int CAPACITY = 80;

//int findSize(char arr[], int capacity);
void reverse(char arr[], int size);
void swap(char *first, char *second);

int main(){
  char input[CAPACITY];
  cout << "Enter string: ";
  std::cin.getline(input, CAPACITY);
  int size = std::strlen(input);
  cout << input << ":" << size << endl;
  reverse(input, size);
  cout << input << endl;
  return 0;
}

/*
int findSize(char arr[], int capacity){
  int count;
  while(count < capacity && arr[count] != '\0'){
    count++;
  }
  return count;
}
*/

void reverse(char arr[], int size){
  if(size > 0){
    char *head = NULL;
    char *tail = NULL;
    head = arr;
    tail = &arr[size-1];
    while(head < tail){
      swap(head, tail);
      head++;
      tail--;
    }
  }
}