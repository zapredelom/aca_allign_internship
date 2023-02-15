#include <algorithm>
#include <iostream>
#include <mutex>
#include <ranges>
#include <thread>
#include <vector>
#include <map>
#include <chrono>

#include "Primes.hpp"
#include "BusyWait.hpp"
#include "ExpirationCache.hpp"
using namespace std::literals::chrono_literals;
int main() {
  ExpirationCache e(200ms);
  e.set("100", "hundred");
  std::cout<<e.get("100").value()<<std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(250));


    auto val = e.get("100");
    if(val) {
      std::cout<<val.value();
    } else {
      std::cout<<"no value\n";
    }
 
}