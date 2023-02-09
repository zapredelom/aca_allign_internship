#include <chrono>
#include <iostream>
#include <utility>
#include <optional>
#include <cmath>

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

auto pow(auto val, int p) -> decltype(val) {
  if (p == 1) return val;
  if (p == 0) return 1;
  decltype(val) ret = 1;
  while (p > 0) {
    if (p & 1) ret = ret * val;
    val = val * val;
    p >>= 1;
  }
  return ret;
}

auto pow_recursive(auto val, int p) -> decltype(val) {
  if (p == 1) return val;
  if (p == 0) return (decltype(val))1;
  auto mantis = (p & 1) * val;
  mantis = mantis ? mantis : 1;
  auto base = pow_recursive(val, p / 2);
  return mantis * base * base;
}

template <int p, bool isOdd = p % 2>
struct Pow;

template <int p>
struct Pow<p, false> {
  double operator()(double d) { return Pow<p / 2>()(d) * Pow<p / 2>()(d); };
};

template <int p>
struct Pow<p, true> {
  double operator()(double d) { return d * Pow<p / 2>()(d) * Pow<p / 2>()(d); };
};

template <>
struct Pow<0, false> {
  double operator()(double d) { return 1; };
};

template <>
struct Pow<1, true> {
  double operator()(double d) { return d; };
};

static volatile double i = 0;

template <int pow, typename T, T... ints>
void iterate_2(std::integer_sequence<T, ints...>& int_sec) {
  ((i = Pow<pow>()(ints)), ...);
}

template <typename T, T... ints>
void iterate_1(std::integer_sequence<T, ints...>& int_seq) {
  auto sq = std::make_integer_sequence<int, sizeof...(ints)>{};
  ((iterate_2<ints>(sq)), ...);
}

template <int count>
void testPow() {
  auto sq = std::make_integer_sequence<int, count>{};
  iterate_1(sq);
}

// int main() {
//   constexpr int edge = 1000;
//   {
//     Measurer m;
//     testPow<edge>();
//   }
//   {
//     Measurer m;
//     for (int i = 0; i < edge; i++) {
//       for (int j = 0; j < edge; j++) {
//         volatile int k = pow(i, j);
//       }
//     }
//   }
//   {
//     Measurer m;
//     for (int i = 0; i < edge; i++) {
//       for (int j = 0; j < edge; j++) {
//         volatile int k = pow_recursive(i, j);
//       }
//     }
//   }
//   // auto round = [](auto val) {
//   //     return magic(val);
//   // };

//   // auto dval1 = round(1.234f);
//   // auto dval2 = round(1.234F);
//   // auto dval3 = round(1.23l);
//   // auto dval4 = round(1.234L);
//   // auto ival = round(12);

//   std::cout << "\ndone!\n";
// }

std::optional<int> sqrt(int i)
{
  if(i >= 0){
    return std::sqrt(i);
  } else {
    std::optional<int> ret;
    return ret;
  }
}

template < typename T>
struct is_optional: public std::false_type {

};

template <typename T>
struct is_optional<std::optional<T>> : public std::true_type{

};

template <typename T>
struct is_const: std::false_type {

};

template <typename T>
struct is_const<const T>: std::true_type {
};

template <typename T>
struct TypeIdentity {
  using type = T;
};




template <typename T>
using TypeIdentity_t = typename TypeIdentity<T>::type;


template <typename T>
T sum (T a, TypeIdentity_t<T> b)
{
  return a+b;
}

void value(int a){
  std::cout<<a<< " is plain value"<<std::endl;
}

void value(const int& a){
  std::cout<< a << " is const referance"<<std::endl;
}

template <typename T>
struct ValueType{
  using type = T;
  ValueType(T a):_a(a){
  }
  void operator()(){
    std::cout<<_a<< " is plain value"<<std::endl;
  }
  T _a;
};

template <typename T>
struct ValueType<T&>{
  using type = T;
  ValueType(T& a):_a(a){
  }
  void operator()(){
    std::cout<< _a << " is referance"<<std::endl;
  }
  T& _a;
};

int main (){
  int a = 1;
  int& c = a;
  double b = 2;
  ValueType<decltype(a)> x(a);
  x();
}



