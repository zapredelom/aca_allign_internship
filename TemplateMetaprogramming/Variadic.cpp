#include <iostream>
#include <string>
#include <tuple>


template <typename... Args>
void f(Args... args) {
    static_assert((std::is_same_v<Args, int> &&  ...), "all should be int") ;
}

int main() {
    int a = 1;
    int b = 5;
    std::string str{"test"};
    std::tuple values{a, b, str};

    f(a, b, b);
}