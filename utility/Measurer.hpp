
#include <chrono>
#include <iostream>

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