class NullPtrDereference{};
template<typename T>
class WrongPtr{
public:
    WrongPtr(): _ptr(nullptr){}
    WrongPtr(T* ptr): _ptr(ptr){(*_cout)++;}
    WrongPtr(const WrongPtr& other)(_ptr = other._ptr;_count = other.count , (*_count)++);
    WrongPtr(WrongPtr&& other):_ptr(other._ptr) {
        other._ptr = nullptr;
    }
    T operator*() {
        if(_ptr == nullptr) throw new NullPtrDereference();
        return *_ptr;
    }
    T operator=(const WrongPtr& other) = delete;
    T operator=(const WrongPtr&& other) {
        _ptr(other._ptr);
        other._ptr=nullptr;
    }

    ~WrongPtr() {
        (*_count)--;
        if(_count == 0)
            delete _ptr;
        _ptr = nullptr;
    }
private:
    T* _ptr;
    int* _count;
};

