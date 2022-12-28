#include <iostream>

template <class T = double>
T pow(double x, int y) {
    return x*y;
}

template<class T>
class tmpClass {
    public:
    tmpClass(T x):value(x){}
    tmpClass():value(0){}
    tmpClass(const tmpClass& op2){}
    private:
    T value;
};

template<>
class tmpClass<int>;

template <int T>
class factorial{
public:
    static const int value = T * factorial<T - 1>::value;

};

template <>
class factorial <0>{
    public:
    static const int value = 1;
};

int main ()
{

    std::cout<<factorial<10>::value;

}