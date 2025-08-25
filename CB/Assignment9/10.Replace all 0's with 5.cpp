#include <iostream>
using namespace std;

int convert0To5(int n) {
    // Base case
    if (n == 0)
        return 0;

    // Extract last digit
    int digit = n % 10;
    if (digit == 0) {
        digit = 5;
    }

    // Recursion case: build number from higher digits
    return convert0To5(n / 10) * 10 + digit;
}

int main() {
    int n;
    cin >> n;

    // Special case when input itself is 0
    if (n == 0) {
        cout << 5 << endl;
    } else {
        cout << convert0To5(n) << endl;
    }

    return 0;
}
