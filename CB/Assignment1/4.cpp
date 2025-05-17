#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0 || N >= 100) {
        cout << "N <= 0 or N >= 100." << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        cout << i << "\t";  // Print the first number

        // Print middle 0s if i > 2
        for (int j = 1; j < i - 1; j++) {
            cout << "0\t";
        }

        // Print the last number if i > 1
        if (i > 1) {
            cout << i;
        }

        cout << endl;
    }

    return 0;
}
