#include "Animal.hpp"
#include <iostream>
#include <vector>

class Exception{};
void f([[maybe_unused]] int x) {
    static int initial_value = 0;
    std::cout<<initial_value<<std::endl;
    if( initial_value == 4) {
        initial_value++;
        throw initial_value;
    } else {
        initial_value++;
    }

}


void g(){}

int main () {
std::vector<int> v;
v.empty();
    try{
        g();
    } catch (int a) {
        g();
    }
}