#include <iostream>

enum class Color {
    red, green = 20, blue
};

int main() {
    Color r = Color::blue;

    switch(r) {
        case Color::red: std::cout << "red\n"; break;
        case Color::green: std::cout << "green\n"; break;
        case Color::blue: std::cout << "blue\n"; break;
    }

//  int n = r; // error
    int n = static_cast<int>(r); // OK, n = 21
    Color color = static_cast<Color>(22); // UB, but allowed
}
