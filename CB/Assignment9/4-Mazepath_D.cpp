#include <iostream>
using namespace std;

void printPaths(int n, int m, string path) {
    // Base case
    if (n == 1 && m == 1) {
        cout << path << " ";
        return;
    }

    // Recursion case: move vertically (V)
    if (n > 1) {
        printPaths(n - 1, m, path + "V");
    }

    // Recursion case: move horizontally (H)
    if (m > 1) {
        printPaths(n, m - 1, path + "H");
    }

    // Recursion case: move diagonally (D)
    if (n > 1 && m > 1) {
        printPaths(n - 1, m - 1, path + "D");
    }
}

int countPaths(int n, int m) {
    // Base case
    if (n == 1 && m == 1) return 1;

    int count = 0;

    // Recursion case: move vertically (V)
    if (n > 1) {
        count += countPaths(n - 1, m);
    }

    // Recursion case: move horizontally (H)
    if (m > 1) {
        count += countPaths(n, m - 1);
    }

    // Recursion case: move diagonally (D)
    if (n > 1 && m > 1) {
        count += countPaths(n - 1, m - 1);
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    printPaths(n, m, "");
    cout << endl;

    cout << countPaths(n, m) << endl;

    return 0;
}
