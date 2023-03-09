#include "thread_pull.h"

#include <chrono>
using namespace std::chrono_literals;

ThreadPool::ThreadPool() : _thread_count(std::thread::hardware_concurrency()) { initWorkers(); }

void ThreadPool::worker() {
    while (_isRunning) {
        Task task;
        {
            std::unique_lock lock(_mutex);
            _cv.wait(lock, [this]() { return !_tasks.empty() || !_isRunning; });
            if (_isRunning) {
                task = _tasks.front();
                _tasks.pop();
            }
        }
        if (task) {
            task();
        }
    }
}

void ThreadPool::initWorkers() {
    for (int i = 0; i < _thread_count; i++) {
        _threads.emplace_back(&ThreadPool::worker, this);
    }
}

ThreadPool::~ThreadPool() {
    _isRunning = false;
    {
        std::scoped_lock lc(_mutex);
        _tasks = {};
    }
    _cv.notify_all();
    for (auto& t : _threads) {
        t.join();
    }
}
