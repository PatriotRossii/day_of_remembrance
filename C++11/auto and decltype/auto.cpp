#include <iostream>
#include <utility>

// auto discards cv qualifiers and references

const int some_int{0};

template<class T, class U>
auto add(T t, U u) { return t + u; }

const int& foo() {
    return some_int;
}

template<class F, class... Args>
decltype(auto) PerfectForward(F fun, Args&&... args) {
    return fun(std::forward<Args>(args)...);
}

template<auto n>
auto f() -> std::pair<decltype(n), decltype(n)> {
    return {n, n};
}

int main() {
    auto a = 1 + 2; // type of a is int
    auto b = add(1, 1.2); // type of b is double

    static_assert(std::is_same_v<decltype(a), int>);
    static_assert(std::is_same_v<decltype(b), double>);

    auto i = foo(); // type of i is int
    decltype(auto) i2 = foo(); // type of i2 is const int&&

    auto c0 = a; // type of c0 is int, holding a copy of a
    decltype(auto) c1 = a; // type of c1 is int, holding a copy of a
    decltype(auto) c2 = (a); // type of c2 is int&, an alias of a

    std::cout << "a, before modification through c2 = " << a << '\n';
    ++c2;
    std::cout << "a, after modification through c2 = " << a << '\n';

    auto [v, w] = f<0>(); // structured binding declaration

    auto d = {1, 2}; // OK: type of d in std::initializer_list<int>
    auto n = {5}; // OK: type of n is std::initializer_list<int>
//  auto e{1, 2}; // Error
    auto m{5};  // OK: type of m is int
//  decltype(auto) z = {1, 2} // Error: {1, 2} is not an expression

    auto lambda = [](int x) { return x + 3; };

//  auto int x; // valid C++98, error as of C++11
//  auto x;     // valid C, error in C++
}
