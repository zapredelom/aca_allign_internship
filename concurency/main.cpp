#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <mutex>
#include <ranges>
#include <thread>
#include <vector>

#include "BusyWait.hpp"
#include "ExpirationCache.hpp"
#include "Primes.hpp"
using namespace std::literals::chrono_literals;
int main() {
    ExpirationCache<std::string, std::string> e(200ms);
    e.set("100", "hundred");
    std::cout << e.get("100").value() << std::endl;
    std::this_thread::sleep_for(215ms);
    auto val = e.get("100");

    if (val) {
        std::cout << val.value()<<std::endl;
    } else {
        std::cout << "no value\n";
    }
}