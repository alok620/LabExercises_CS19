#include <iostream>

using std::cout;
using std::endl;

void deleteRepeats(char a[], int& size);
void printArray(char a[], int size);
void format(char a[], int size);

int main(){
  char a[10];
  a[0] = 'a';
  a[1] = 'a';
  a[2] = 'd';
  a[3] = 'c';
  int size = 4;
  deleteRepeats(a, size);
  printArray(a, size);
}

void deleteRepeats(char a[], int& size){
  for(int i = 0; i < size-1; i++){
    for(int j = i+1; j < size; j++){
      if(a[j] == a[i]){
        a[j] = '\0';
        format(a, size);
        size--;
      }
    }
  }
}

void format(char a[],int size){
  for(int i = 0; i < size; i++){
    if(a[i] == '\0'){
      for(int j = i; j < size-1; j++){
        a[j] = a[j+1];
      }
    }
  }
}

void printArray(char a[], int size){
  for(int i = 0; i < size; i++){
    cout << a[i] << endl;
  }
}