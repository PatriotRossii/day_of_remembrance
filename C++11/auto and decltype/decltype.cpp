#include <iostream>
#include <type_traits>

struct A { double x; };
const A* a;

decltype(a->x) y;   // type of y is double
decltype((a->x)) z = y; // type of z is const double&

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {
    int i = 3;
    decltype(i) j = i * 2;

    std::cout << "i and j are the same type? " << std::boolalpha
              << std::is_same_v<decltype(i), decltype(j)> << '\n';

    std::cout << "i = " << i << ", "
              << "j = " << j << '\n';

    auto f = [](int a, int b) -> int {
        return a * b;
    };

    decltype(f) g = f; // the type of a lambda function is unique and unnamed

    i = f(2, 2);
    j = g(3, 3);

    std::cout << "i = " << i << ", "
              << "j = " << j << '\n';
}
