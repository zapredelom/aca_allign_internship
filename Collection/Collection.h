#include <initializer_list>
#include <algorithm>
template <typename T>
class Array{
public:
    Array();
    explicit Array(int preallocationSize);
    Array(const Array&);
    Array(const Array&&);
    Array(std::initializer_list<T>);
    [[nodiscard]] T& operator [](int index) {return _data[index];}
    int size() { return _size;}
    int capacity() { return _capacity;}
    void push_back(T t);


    ~Array() {delete [] _data;}
private:
    int _capacity;
    int _size;
    T* _data;

private: // magic numbers
    static const int kDefaultCapacity = 10;
};


template <typename T>
Array<T>::Array(): Array(kDefaultCapacity) {}


template <typename T>
Array<T>:: Array(int size):
    _capacity(size), _size(0), _data(new T[_capacity])
{
}

template<typename T>
Array<T> :: Array(const Array<T>& op2) : Array(op2._capacity)
{
    std::memcpy(op2._data, _data, sizeof(T) * op2._size);
    _size = op2._size;

}
template<typename T> 
Array<T>::Array(Array&& other){
    _data = other._data;
    _size = other._size;
    _capacity = other._capacity;
    other._data = nullptr;
}

template<typename T>
Array<T>::Array(std::initializer_list<T> lst):
    Array(lst.size()) {
        for(const T& t: lst) {
            _data[_size++] = t;
        }
    }
template<typename T> 
void Array<T>::push_back(T t) {
    if( _size < _capacity) {
        _data[_size++] = t;
    } else {
        T* new_data = new T[_capacity * 2];
        std::memcopy(new_data, _data, sizeof(T)*_size);
        delete [] _data;
        _data = new_data;
    }
}
