#include <chrono>
#include <unordered_map>
#include <string>
#include <optional>
#include <shared_mutex>

class ExpirationCache{
    public:
        ExpirationCache(std::chrono::milliseconds expirationTime);
        void set(const std::string& key, const std::string& value);
        std::optional<std::string> get(const std::string& key);
        ~ExpirationCache();

    private:
        void worker();

    private:
        std::unordered_map<std::string, std::string> _data;
        std::chrono::milliseconds _duration;
        bool _isAlive;
        std::shared_mutex _lock;
        std::thread _workerThread;
};