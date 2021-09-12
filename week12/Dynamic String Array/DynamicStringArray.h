#ifndef DYNAMIC_STRING_ARRAY__H
#define DYNAMIC_STRING_ARRAY__H
#include <iostream>

class DynamicStringArray{
 private:
  std::string *dynamicArray;
  int size;
 public:
  DynamicStringArray();
  DynamicStringArray(DynamicStringArray &);
  ~DynamicStringArray();
  int getSize() {return size;}
  void addEntry(std::string);
  bool deleteEntry(std::string);
  std::string getEntry(int index);
  void operator=(const DynamicStringArray &) const;

};


#endif