#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> mat(R, vector<int>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> mat[i][j];
        }
    }

    int maxSum = INT_MIN;
    for (int i = 1; i < R - 1; ++i) {
        for (int j = 1; j < C - 1; ++j) {
            int sum = mat[i-1][j-1] + mat[i-1][j] + mat[i-1][j+1]
                    + mat[i][j]
                    + mat[i+1][j-1] + mat[i+1][j] + mat[i+1][j+1];
            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << endl;
    return 0;
}