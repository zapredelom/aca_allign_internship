#include <chrono>
#include <future>
#include <iostream>
#include <map>

#include "thread_pull.h"
using namespace std::chrono_literals;
using namespace std::string_literals;

int square(int a) { return a * a; }

double add(double a, double b) { return a + b; }

std::future<double> addAsync(double a, double b) {
    std::promise<double> p;
    std::future<double> f = p.get_future();
    std::thread t([a, b, p = std::move(p)]() mutable {
        std::this_thread::sleep_for(3s);
        p.set_value(a + b);
    });
    t.detach();
    return f;
}

int main() {
    std::vector<int> t {1,2,3,4,5};
    std::vector<int> x;

    std::copy(t.begin(), t.end(),std::back_inserter(x));
    // ThreadPool t;
    // std::mutex outMutex;

    // std::vector<std::future<int>> futures;
    // for (int i = 0; i < 100; i++) {
    //     auto task = [i, &outMutex](int x) -> int {
    //         std::this_thread::sleep_for(1ms);
    //         std::scoped_lock lk(outMutex);
    //         std::cout << "task number " << x << " thread id " << std::this_thread::get_id() << std::endl;
    //         return 1;
    //     };
    //     futures.push_back(t.addTask(task, 3));
    // }
    // for (auto& f : futures) {
    //     std::cout << f.get() << std::endl;
    // }

    // std::future<int> ft = std::async(square, 5);
    // std::cout << ft.get() << std::endl;

    // std::future<double> ft1 = addAsync( 5, 6);
    // std::cout << ft1.get() << std::endl;

}
