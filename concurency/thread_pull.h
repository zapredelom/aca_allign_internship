#include <functional>
#include <queue>
#include <thread>
#include <mutex>
#include <future>


class ThreadPool {
public:
    using Task = std::function<void()>;

    ThreadPool();
    std::future<void> addTask(Task f);
    ~ThreadPool();

private:
    void initWorkers();
    void worker();

private:
    std::mutex _mutex;
    std::condition_variable _cv;
    std::queue<std::pair<Task, std::promise<void> > > _tasks;
    std::vector<std::thread> _threads;
    int _thread_count;
    bool _isRunning = true;
};
