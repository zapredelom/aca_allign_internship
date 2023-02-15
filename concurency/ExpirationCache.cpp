#include "ExpirationCache.hpp"

ExpirationCache::ExpirationCache(std::chrono::milliseconds duration) :
    _duration(duration),
    _isAlive(true),
    _workerThread([this](){
        while(_isAlive){
            std::this_thread::sleep_for(_duration);
            worker();
        }
    })
{
}

void ExpirationCache::set(const std::string& key, const std::string& value) {
    std::unique_lock l(_lock);
    _data[key] = value;
}

std::optional<std::string> ExpirationCache::get(const std::string& key) {
    std::shared_lock l(_lock);
    if(_data.contains(key)){
        return _data[key];
    }
    return std::optional<std::string>();
}

void ExpirationCache::worker() {
    std::unique_lock l(_lock);
    _data.clear();
}

ExpirationCache::~ExpirationCache(){
    _isAlive = false;
    _workerThread.join();
}



