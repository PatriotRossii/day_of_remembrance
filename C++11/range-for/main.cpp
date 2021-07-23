#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5};

    for(const int& i: v) { } // access by const reference
    for(auto i: v) { } // access by value
    for(auto&& i: v) { } // access by forwarding reference, the type of i is int&

    const auto& cv = v;

    for(auto&& i: cv) {} // access by f-d reference, the type of i is const int&
    for(int n: {0, 1, 2, 3, 4, 5}) {} // the initializer may be a braced-init-list

    int array[] = {0, 1, 2, 3, 4, 5};
    for(int n: array) { } // the initializer may be an array

    for(auto n = v.size(); auto i : v) { } // the init-statement (C++20)
}
