#include <iostream>
#include <string>
#include <array>

using std::cout;
using std::endl;
using std::array;

bool contains (char * haystack, char * needle);
bool controlNeedle(char * haystack, char * nextHaystack,
                   char * needle, char * origNeedle);

int main() {
  array<char, 5> haystack;
  haystack[0] = 'a';
  haystack[1] = 'b';
  haystack[2] = 'c';
  haystack[3] = 'b';
  haystack[4] = 'a';

  array<char, 2> needle;
  needle[0] = 'b';
  needle[1] = 'a';

  cout << contains("programming", "ogra") << endl;
  if(contains("programming", "ogra")){
    cout << "true" << endl;
  }
}

bool contains (char * haystack, char * needle){
  return controlNeedle(haystack, haystack + 1, needle, needle);
}

bool controlNeedle(char * haystack, char * nextHaystack,
                   char * needle, char * origNeedle){
  if(*needle == '\0'){
    return true;
  } else if(*haystack == '0'){
    return false;
  }

  if(*haystack == *needle){
    return controlNeedle(haystack + 1, nextHaystack,
                         needle + 1, origNeedle);
  }else{
    return controlNeedle(nextHaystack, nextHaystack + 1,
                         origNeedle, origNeedle);
  }

}