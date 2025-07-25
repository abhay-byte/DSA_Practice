#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> mat(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> mat[i][j];

    bool isToeplitz = true;
    for (int i = 0; i < M - 1; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            if (mat[i][j] != mat[i + 1][j + 1]) {
                isToeplitz = false;
                break;
            }
        }
        if (!isToeplitz) break;
    }
    cout << (isToeplitz ? "true" : "false") << endl;
    return 0;
}