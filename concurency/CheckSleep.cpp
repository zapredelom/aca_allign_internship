#include <chrono>
#include <iostream>
#include <thread>
using namespace std::chrono_literals;
int main() {
    std::thread t1([]() {
        int i = 0;
        while (i++ < 10) {
            auto now = std::chrono::steady_clock::now();
            std::cout << "t1 " << std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch())<< std::endl;
            std::this_thread::sleep_for(100ms);
        }
    });

    std::thread t2([]() {
        int i = 0;
        while (i++ < 10) {
            auto now = std::chrono::steady_clock::now();
            std::cout << "t2 " << std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) << std::endl;
            std::this_thread::sleep_for(100ms);
        }
    });
    t1.join();
    t2.join();
}