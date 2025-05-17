#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        // Print numbers from 1 to N - i
        for (int j = 1; j <= N - i; j++) {
            cout << j << " ";
        }

        // Print stars: (2 * i - 1) stars if i > 0
        for (int k = 0; k < 2 * i - 1; k++) {
            cout << "* ";
        }

        cout << endl;
    }

    return 0;
}
