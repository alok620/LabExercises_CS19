#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

struct StudentInfo{
  std::string name;
  int grade;
};

void print(std::vector<StudentInfo>);
bool cmpStudInf(const StudentInfo &, const StudentInfo &);
bool cmpGrades(const StudentInfo &, const StudentInfo &);


int main(){
  std::stringstream ss;
  std::string input;
  StudentInfo temp;
  std::vector<StudentInfo> inf;
  int total = 0, count = 0;

  std::cout << "Enter name and grade\n";
  while(std::getline(std::cin, input)){
    ss << input;
    ss >> temp.name;
    ss >> temp.grade;
    inf.push_back(temp);
    ss.clear();
    total += temp.grade;
    count++;
  }
  std::cout << "--------------\n";

  std::sort(inf.begin(), inf.end(), cmpStudInf);

  std::pair<std::vector<StudentInfo>::iterator, std::vector<StudentInfo>::iterator> hiLoIterators;
  hiLoIterators = std::minmax_element(inf.begin(), inf.end(), cmpGrades);

  std::pair<int, int> hiLoGrades;
  hiLoGrades.first = inf[hiLoIterators.first - inf.begin()].grade;
  hiLoGrades.second = inf[hiLoIterators.second - inf.begin()].grade;

  print(inf);
  std::cout << "Min: Max: = " << hiLoGrades.first << ": " << hiLoGrades.second << "\n";
  std::cout << "Avg. Grade: " << total/count << "\n";

  return 0;
}

void print(std::vector<StudentInfo> inf){
  for(unsigned i = 0; i < inf.size(); i++){
    std::cout << inf[i].name << ": " << inf[i].grade << "\n";
  }
}

bool cmpStudInf(const StudentInfo &a, const StudentInfo &b){
  return a.name <= b.name;
}

bool cmpGrades(const StudentInfo &a, const StudentInfo &b){
  return a.grade <= b.grade;
}