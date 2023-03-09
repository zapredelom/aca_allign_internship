#include <functional>
#include <future>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <type_traits>

class ThreadPool {
public:
    using Task = std::function<void()>;

    ThreadPool();
    template <typename Fn, typename... Args, typename Ret = typename std::invoke_result<Fn, Args...>::type>
    std::future<Ret> addTask(Fn fn, Args... args);
    ~ThreadPool();

private:
    void initWorkers();
    void worker();

private:
    std::mutex _mutex;
    std::condition_variable _cv;
    std::queue<Task> _tasks;
    std::vector<std::thread> _threads;
    int _thread_count;
    bool _isRunning = true;
};

template <typename Fn, typename... Args, typename Ret>
std::future<Ret> ThreadPool::addTask(Fn fn, Args... args) {
    std::scoped_lock lock(_mutex);
    std::shared_ptr<std::promise<Ret>> p = std::make_shared<std::promise<Ret>>();
    std::future<Ret> fut = p->get_future();
    if (_isRunning) {
        auto task = [p, fn, args...]() { p->set_value(fn(args...)); };
        _tasks.emplace(task);
        _cv.notify_one();
    }
    return fut;
}
