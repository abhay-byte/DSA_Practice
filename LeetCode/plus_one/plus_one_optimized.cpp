#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i]++; // Increment and return
            return digits;
        }
        digits[i] = 0; // Set to 0 and continue
    }

    // If all digits are 9
    digits.insert(digits.begin(), 1);
    return digits;
}

int main() {
    std::vector<int> digits = {9, 9, 9};
    std::vector<int> result = plusOne(digits);

    std::cout << "Result (Optimized): ";
    for (int digit : result) {
        std::cout << digit;
    }
    std::cout << std::endl;

    return 0;
}
