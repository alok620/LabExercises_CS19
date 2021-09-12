#include <iostream>
#include "DynamicStringArray.h"

DynamicStringArray::DynamicStringArray(){
  size = 0;
  dynamicArray = NULL;
}

DynamicStringArray::DynamicStringArray(DynamicStringArray &source){
  size = source.size;
  std::string *temp = new std::string[size];
  for(int i = 0; i < size; i++){
    temp[i] = source.dynamicArray[i];
  }
  delete [] dynamicArray; dynamicArray = NULL;
  dynamicArray = temp;
}

DynamicStringArray::~DynamicStringArray(){
  delete [] dynamicArray; dynamicArray = NULL;
}

void DynamicStringArray::addEntry(std::string entry){
  std::string *temp = new std::string[size+1];
  if(dynamicArray != NULL){
    for(int i = 0; i < size; i++){
      temp[i] = dynamicArray[i];
    }
  }
  delete [] dynamicArray; dynamicArray = NULL;
  dynamicArray = temp;
  dynamicArray[size++] = entry;
}

bool DynamicStringArray::deleteEntry(std::string entry){
  std::string *temp = new std::string[size-1];
  for(int i = 0; i < size; i++){
    if(dynamicArray[i] == entry){
      for(int j = 0, k = 0; j < size; j++){
        if(i != j){
          temp[k++] = dynamicArray[j];
        }
      }
      size--;
      delete [] dynamicArray; dynamicArray = NULL;
      dynamicArray = temp;
      return true;
    }
  }
  return false;
}

std::string DynamicStringArray::getEntry(int index){
  if(index < 0 || index >= size){
    return NULL;
  }
  return dynamicArray[index];
}