#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int array[10][10];

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> array[i][j];

    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int count = 0, total = m * n;

    while (count < total) {
        for (int i = top; i <= bottom && count < total; ++i) {
            cout << array[i][left] << ", ";
            count++;
        }
        left++;

        for (int j = left; j <= right && count < total; ++j) {
            cout << array[bottom][j] << ", ";
            count++;
        }
        bottom--;

        for (int i = bottom; i >= top && count < total; --i) {
            cout << array[i][right] << ", ";
            count++;
        }
        right--;

        for (int j = right; j >= left && count < total; --j) {
            cout << array[top][j] << ", ";
            count++;
        }
        top++;
    }
    cout << "END" << endl;
    return 0;
}