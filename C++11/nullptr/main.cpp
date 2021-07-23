#include <cstddef>
#include <iostream>

template<class T>
constexpr T clone(const T& t) {
    return t;
}

void g(int*) {
    std::cout << "Function g called\n";
}

int main() {
    g(nullptr);
    g(NULL);
    g(0);

    g(clone(nullptr));
//  g(clone(NULL));     // ERROR: non-literal zero cannot be a null pointer constant
//  g(clone(0));        // ERROR: non-literal zero cannot be a null pointer constant
}
