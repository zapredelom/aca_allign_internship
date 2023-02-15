#include <iostream>
#include <mutex>
class BusyWait{
public:
  BusyWait():isDone(true){}
  void worker() {
    std::cout<<"entering worker thread\n";
    lock(); unlock();
    // while(isDone){

    // }
    std::cout<<"done waiting\n";
  }
  void mainWorker() {
    auto timeFrame = std::chrono::seconds(10);
    auto begin = std::chrono::steady_clock::now();
    while(std::chrono::steady_clock::now() < begin + timeFrame) {
      std::cout<<"working in main thread\n";
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    unlock();
  }
  void lock() {
    _lock.lock();
  }
  void unlock() {
    _lock.unlock();
  }
  private:
  bool isDone = false;
  std::mutex _lock;
};
