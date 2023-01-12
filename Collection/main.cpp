// #include "Collection.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <functional>

bool lessInt(int a, int b) { return a < b; }

bool greaterInt(int a, int b) { return a > b; }

class GreateThanObject {
 public:
  bool operator()(int a, int b) { return a > b; }
};

class GreatherFromBase {
 public:
  GreatherFromBase(int baseValue): baseValue(baseValue){}
  bool operator () (int from){return from > baseValue;}
 private:
  int baseValue;
};


typedef bool (*Compare)(int, int);
typedef bool (*flt)(int);

void Filter(std::vector<int>& v, std::function<bool(int)> fn) {
    for(int i: v)
    {
        if(fn(i)){
            std::cout<<i<<std::endl;
        }
    }
}
inline bool isOdd(int i) {
    return i&1;
}


template <typename T>
void F(T t){
    T x =5;
}
std::vector<int> generate(int n) {
    std::vector<int> ret(n);
    for(int i = 0; i < n; i++) {
        ret[i] = i;
    }
    return ret;
}

constexpr int factorial(int n) {
    if( n == 1 ) return 1;
    return n * factorial(n-1);
}
constexpr int fn () {
    return 10;
}
int main() {
  auto genVec = generate(100);
   constexpr int val = 10;
   constexpr int constInt = factorial(fn());

  //constInt++;


  auto flt_lambda = [](int a, int b ){ return a>b;};
  std::vector<int> v{1, 2, 63, 2, 36, 7, 1, 4, 9, 10};

  v.push_back(10);

  std::for_each(begin(v) + 2, end(v) - 1, [](int i){ std::cout<<i<<std::endl;} );
  auto it = begin(v);

}