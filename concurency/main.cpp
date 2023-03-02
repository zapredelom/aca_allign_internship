#include <chrono>
#include <future>
#include <iostream>
#include <map>

#include "thread_pull.h"
using namespace std::chrono_literals;

int square(int a) { return a * a; }
double add(double a, double b) { return a * a; }
int main() {
    ThreadPool t;
    std::mutex outMutex;


    std::vector<std::future<void>> futures;
    for (int i = 0; i < 100; i++) {
        futures.push_back(t.addTask([i, &outMutex]() {
            std::this_thread::sleep_for(1ms);
            std::scoped_lock lk(outMutex);
            std::cout << "task number " << i << " thread id " << std::this_thread::get_id() << std::endl;
        }));
    }
    for (auto& f : futures) {
        f.wait();
    }

    // std::map<int, int> mp;
    // for (auto [key, value] : mp) {
    // }
}
