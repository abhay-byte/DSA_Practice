#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N <= 0 || N >= 100) {
        cout << "N <= 0 or N >= 100." << endl;
        return 0;
    }

    int a = 0, b = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cout << a << "\t";

            // Generate Fibonacci number
            int next = a + b;
            a = b;
            b = next;
        }
        cout << endl;
    }

    return 0;
}
