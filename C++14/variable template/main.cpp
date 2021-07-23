#include <iostream>

template<class T>
constexpr T pi = T(3.1415926535897932385L); // variable template

template<class T>
T circular_area(T r) {
    return pi<T> * r * r;   // pi<T> is a variable template
}

int main() {
    std::cout << "int: " << pi<int> << std::endl;
    std::cout << "float: " << pi<float> << std::endl;
    std::cout << "double: " << pi<double> << std::endl;
    std::cout << "long double: " << pi<long double> << std::endl;
}
