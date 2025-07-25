#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    char mat[1000][1000];

    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    char ch = 'X';

    while (top <= bottom && left <= right) {
        // Fill top row
        for (int i = left; i <= right; ++i)
            mat[top][i] = ch;
        top++;

        // Fill right column
        for (int i = top; i <= bottom; ++i)
            mat[i][right] = ch;
        right--;

        // Fill bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; --i)
                mat[bottom][i] = ch;
            bottom--;
        }

        // Fill left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i)
                mat[i][left] = ch;
            left++;
        }

        // Alternate character
        ch = (ch == 'X') ? '0' : 'X';
    }

    // Print the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mat[i][j];
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}