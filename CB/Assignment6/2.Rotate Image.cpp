#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> mat(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> mat[i][j];

    // Print rotated matrix
    for (int j = N - 1; j >= 0; --j) {
        for (int i = 0; i < N; ++i) {
            cout << mat[i][j];
            if (i != N - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}