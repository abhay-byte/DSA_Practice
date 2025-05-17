#include <iostream>
using namespace std;

void PrintPattern(int N) {
    for (int i = 1; i <= N; i++) {
        // Print the first sequence (1 to i)
        for (int j = 1; j <= i; j++) {
            cout << j << "\t";
        }

        // Print the spaces in between
        int spaces = 2 * (N - i) - 1;
        for (int s = 1; s <= spaces; s++) {
            cout << "\t";
        }

        // Print the second sequence (i to 1), excluding the duplicate in the middle for the last element
        for (int j = i; j >= 1; j--) {
            if (!(i == N && j == i)) {
                cout << j << "\t";
            }
        }

        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    if (N > 0 && N < 10) {
        PrintPattern(N);
    } else {
        cout << "Invalid input. Please enter a value between 1 and 9." << endl;
    }

    return 0;
}
