#include <iostream>
using namespace std;

void printPaths(int n, int row, int col, string path) {
    // Base case
    if (row == n && col == n) {
        cout << path << " ";
        return;
    }

    // Recursion case: move vertically
    if (row < n) {
        printPaths(n, row + 1, col, path + "V");
    }

    // Recursion case: move horizontally
    if (col < n) {
        printPaths(n, row, col + 1, path + "H");
    }

    // Recursion case: move diagonally only if on diagonal
    if (row < n && col < n && (row == col || row + col == n + 1)) {
        printPaths(n, row + 1, col + 1, path + "D");
    }
}

int countPaths(int n, int row, int col) {
    // Base case
    if (row == n && col == n) {
        return 1;
    }

    int count = 0;

    // Recursion case: move vertically
    if (row < n) {
        count += countPaths(n, row + 1, col);
    }

    // Recursion case: move horizontally
    if (col < n) {
        count += countPaths(n, row, col + 1);
    }

    // Recursion case: move diagonally only if on diagonal
    if (row < n && col < n && (row == col || row + col == n + 1)) {
        count += countPaths(n, row + 1, col + 1);
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    printPaths(n, 1, 1, "");
    cout << endl;

    cout << countPaths(n, 1, 1) << endl;

    return 0;
}
