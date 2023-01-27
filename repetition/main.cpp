#include <iostream>
#include <vector>
#include <type_traits>
#include <functional>
#include "Animal.hpp"
int square (int a) {
    return a*a;
}

int qube(int &a) {
    a =  a*a*a;
    return a;
}


template<typename T>
int transform(int a,T f)  {
    return f(a);
}

int transform2(int a, std::function<int(int)> f) {
    return f(a);
}

class Sum {
public:
    int operator()(int b) {
        return b + 1;
    }
};

int main () {
    int a;
    Sum sum;
    std::cout<<transform2(2, square) << std::endl;
    std::cout<<transform2(2, [](int a) {return a*a;})<< std::endl;
    std::cout<<transform2(2, sum)<< std::endl;

}