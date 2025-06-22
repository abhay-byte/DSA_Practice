#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> plusOneBrute(const std::vector<int>& digits) {
    long long number = 0;

    // Convert array to integer
    for (int digit : digits) {
        number = number * 10 + digit;
    }

    // Increment by 1
    number++;

    // Convert the number back to a vector of digits
    std::vector<int> result;
    while (number > 0) {
        result.insert(result.begin(), number % 10);
        number /= 10;
    }

    return result;
}

int main() {
    std::vector<int> digits = {1, 2, 3};
    std::vector<int> result = plusOneBrute(digits);

    std::cout << "Result (Brute Force): ";
    for (int digit : result) {
        std::cout << digit;
    }
    std::cout << std::endl;

    return 0;
}
