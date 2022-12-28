template <typename T>
class Collection{
public:
    Collection();
    Collection(const Collection&);
    Collection(int preallocationSize);

    [[nodiscard]] T& operator[] (int index);
    [[nodiscard]] const T& operator[] (int index) const;

    [[nodiscard]] int size() const;
    [[nodiscard]] int capacity() const;

    ~Collection();
private:
    int _size;
    int _capacity;
    T* _data;



private: // magic numbers
    static const int kDefaultCapacity = 10;

};

template <typename T>
Collection<T>::Collection():_capacity(kDefaultCapacity), _size(0), _data(new T[_capacity]) {

}

