#include "thread_pull.h"

#include <chrono>
using namespace std::chrono_literals;

ThreadPool::ThreadPool() : _thread_count(std::thread::hardware_concurrency()) { initWorkers(); }

std::future<void> ThreadPool::addTask(Task f) {
    std::scoped_lock lock(_mutex);
    std::promise<void> p;
    std::future<void> fut = p.get_future();
    if (_isRunning) {
        _tasks.push({f,std::move(p)});
        _cv.notify_one();
    }
    return fut;
}

void ThreadPool::worker() {
    while (_isRunning) {
        Task task;
        std::promise<void> p;
        {
            std::unique_lock lock(_mutex);
            _cv.wait(lock, [this]() { return !_tasks.empty() || !_isRunning; });
            if (_isRunning) {
                task = _tasks.front().first;
                p = std::move(_tasks.front().second);
                _tasks.pop();
            }
        }
        if (task){
            task();
            p.set_value();
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
