#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        // Print leading spaces
        for (int s = 1; s <= N - i; s++) {
            cout << "\t";
        }

        int num = i;
        // Increasing numbers
        for (int j = 1; j <= i; j++) {
            cout << num++ << "\t";
        }

        num -= 2; // Adjust for decreasing part
        // Decreasing numbers
        for (int j = 1; j < i; j++) {
            cout << num-- << "\t";
        }

        cout << endl;
    }

    return 0;
}
