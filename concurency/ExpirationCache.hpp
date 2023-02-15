#include <chrono>
#include <optional>
#include <shared_mutex>
#include <string>
#include <unordered_map>
using namespace std::chrono_literals;
template <typename _KeyType, typename _ValueType, typename _Hasher = std::hash<_KeyType> >
class ExpirationCache {
    using KeyType = _KeyType;
    using ValueType = _ValueType;
    using Hasher = _Hasher;

public:
    ExpirationCache(std::chrono::milliseconds expirationTime);
    void set(const KeyType& key, const ValueType& value);
    std::optional<ValueType> get(const KeyType& key);
    ~ExpirationCache();

private:
    void worker();

private:
    std::unordered_map<KeyType, ValueType, Hasher> _youngGeneration;
    std::unordered_map<KeyType, ValueType, Hasher> _oldGeneration;

    std::chrono::milliseconds _duration;
    bool _isAlive;
    std::shared_mutex _lock;
    std::thread _workerThread;
};

template <typename _KeyType, typename _ValueType, typename _Hasher>
ExpirationCache<_KeyType, _ValueType, _Hasher>::ExpirationCache(std::chrono::milliseconds duration)
    : _duration(duration), _isAlive(true), _workerThread([this]() {
          while (_isAlive) {
              std::this_thread::sleep_for(std::chrono::milliseconds(_duration.count() / 2));
              worker();
          }
      }) {}

template <typename _KeyType, typename _ValueType, typename _Hasher>
void ExpirationCache<_KeyType, _ValueType, _Hasher>::set(const _KeyType& key, const _ValueType& value) {
    std::unique_lock l(_lock);
    _youngGeneration[key] = value;
}

template <typename _KeyType, typename _ValueType, typename _Hasher>
std::optional<_ValueType> ExpirationCache<_KeyType, _ValueType, _Hasher>::get(const _KeyType& key) {
    std::shared_lock l(_lock);
    if (_youngGeneration.contains(key)) {
        return _youngGeneration[key];
    }
    if (_oldGeneration.contains(key)) {
        return _oldGeneration[key];
    }
    return std::optional<_ValueType>();
}

template <typename _KeyType, typename _ValueType, typename _Hasher>
void ExpirationCache<_KeyType, _ValueType, _Hasher>::worker() {
    std::unique_lock l(_lock);
    _oldGeneration = std::move(_youngGeneration);
    _youngGeneration.clear();
}

template <typename _KeyType, typename _ValueType, typename _Hasher>
ExpirationCache<_KeyType, _ValueType, _Hasher>::~ExpirationCache() {
    _isAlive = false;
    _workerThread.join();
}
