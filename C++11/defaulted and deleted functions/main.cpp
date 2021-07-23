#include <iostream>

#include <utility>

struct A {
    A() {
        std::cout << "A()" << std::endl;
    }

    A(const A&) {
        std::cout << "A(const A&)" << std::endl;
    }

    A(const A&&) {
        std::cout << "A(const A&&)" << std::endl;
    }

    A& operator=(const A&) {
        std::cout << "A& operator=(const A&)" << std::endl;
        return *this;
    }
    A& operator=(A&&) {
        std::cout << "A& operator=(A&&)" << std::endl;
        return *this;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

int main() {
    A a;
    A other_a;

    A{other_a};
    A{A{}};

    A variable = a;
    A another_variable = std::move(variable);
}
