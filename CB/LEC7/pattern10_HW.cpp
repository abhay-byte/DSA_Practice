#include <iostream>

int main() {
    int height = 5;

    // Upper half of the diamond
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    // Lower half of the diamond
    for (int i = height - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }

    return 0;
}