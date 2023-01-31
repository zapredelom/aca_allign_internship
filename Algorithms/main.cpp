#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <ranges>
#include <unordered_map>

#include "DynamicProgramming.hpp"

class Measurer {
 public:
  Measurer() : _begin(std::chrono::steady_clock::now()) {}
  ~Measurer() {
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                      _begin)
                     .count()
              << std::endl;
  }

 private:
  std::chrono::time_point<std::chrono::steady_clock> _begin;
};

void merge_sort(std::vector<int>& v, int begin, int end);
void merge(std::vector<int>& v, int begin, int mid, int end);

void sort(std::vector<int>& v) { merge_sort(v, 0, v.size()); }

void buble_sort(std::vector<int>& v, int begin, int end) {
  for (int i = begin; i < end; i++) {
    for (int j = i; j < end; j++) {
      if (v[i] >= v[j]) std::swap(v[i], v[j]);
    }
  }
}

void merge_sort(std::vector<int>& v, int begin, int end) {
  if (end - begin <= 128) {
    buble_sort(v, begin, end);
    return;
  }

  int mid = begin + (end - begin) / 2;

  merge_sort(v, begin, mid);
  merge_sort(v, mid, end);
  merge(v, begin, mid, end);
}

void merge(std::vector<int>& v, int begin, int mid, int end) {
  int index1 = begin;
  int index2 = mid;
  std::vector<int> tmp;
  while (index1 < mid && index2 < end) {
    if (v[index1] < v[index2]) {
      tmp.push_back(v[index1]);
      index1++;
    } else {
      tmp.push_back(v[index2]);
      index2++;
    }
  }
  while (index1 < mid) {
    tmp.push_back(v[index1++]);
  }
  while (index2 < end) {
    tmp.push_back(v[index2++]);
  }
  for (int i : tmp) {
    v[begin] = i;
    begin++;
  }
}
bool isValidNumber(const std::string& numstr){
  if(numstr.size() >3) return false;
  bool isLeadingZero = numstr.size() > 1 && numstr[0] == '0';
  if(isLeadingZero) return false;
  int value = 0;
  int ten = 1;
  for(int i = numstr.size() - 1; i >= 0; --i){
    if(numstr[i] <'0' || numstr[i] > '9') return false;
    value += ten * (numstr[i] - '0');
    ten *= 10;
  }
  if(value > 255) return false ;
  return true;
}
bool IsValidIp(const std::string& ip){
  auto DotCount = std::count_if(begin(ip), end(ip), [](char ch) {return ch == '.'; });
  // alternatively can be writen
  // auto DotCount = std::count(begin(ip), end(ip), '.');
  if(DotCount != 3) return false;
  std::string current = "";
  int currentIndex = 0;
  do{
    if(ip[currentIndex] != '.'){
      current += ip[currentIndex];
    } else {
      if(!isValidNumber(current)) return false;
      current = "";
    }
    currentIndex++;
  } while(currentIndex < ip.size());
  return true;
}

int main() {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution dis(1,1000);
  constexpr int count = 1000;

  std::vector<int> prices;
  std::generate_n(std::back_inserter(prices), count, [&mt, &dis](){return dis(mt);});
  sort(prices);

  // { // uncomment this seconion for values no more than 50, othewise it will take too long to compleate
  //   Measurer m;
  //   Cut(prices, prices.size());
  // }
  {
    Measurer m;

    std::unordered_map<int, int> mem;
    Cut(prices, prices.size(), mem);
  }
  {
    Measurer m;
    Cut_buttom_up(prices, prices.size());
  }
}

