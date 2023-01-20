#include "Animal.hpp"
#include <iostream>

class Exception{};
void f([[maybe_unused]] int x) throw(int) {
    static int initial_value = 0;
    std::cout<<initial_value<<std::endl;
    if( initial_value == 4) {
        initial_value++;
        throw initial_value;
    } else {
        initial_value++;
    }

}

[[nodiscard]] bool isEmtpy() noexcept;


int main () {
std::vector<int> v;
v.empty();
    try{
        g();
    } catch (int a) {
        g();
    }
}