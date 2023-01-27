#include <chrono>
#include <iostream>
#include <random>
#include <vector>

class Measurer {
 public:
  Measurer() : _begin(std::chrono::steady_clock::now()) {}
  ~Measurer() {
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end -
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
int main() {
  constexpr int length = 1000000;
  std::vector<int> v;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, length);

  auto begin = std::chrono::steady_clock::now();
  for (int n = 0; n < length; ++n) {
    v.push_back(dis(gen));
  }
  auto end = std::chrono::steady_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
            << std::endl;

    {
        Measurer m;
        sort(v);
    }
  // buble_sort(v, 0, v.size());
  // std::for_each(begin(v), end(v), [](int i){std::cout<<i<<" ";});
}