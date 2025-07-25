#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int arr[10][10];

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];

    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int count = 0, total = m * n;

    while (count < total) {
        // Print left column (top to bottom)
        for (int i = top; i <= bottom && count < total; ++i) {
            cout << arr[i][left] << ", ";
            count++;
        }
        left++;

        // Print bottom row (left to right)
        for (int j = left; j <= right && count < total; ++j) {
            cout << arr[bottom][j] << ", ";
            count++;
        }
        bottom--;

        // Print right column (bottom to top)
        for (int i = bottom; i >= top && count < total; --i) {
            cout << arr[i][right] << ", ";
            count++;
        }
        right--;

        // Print top row (right to left)
        for (int j = right; j >= left && count < total; --j) {
            cout << arr[top][j] << ", ";
            count++;
        }
        top++;
    }
    cout << "END" << endl;
    return 0;
}