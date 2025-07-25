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

    vector<int> result;
    for (int d = 0; d < M + N - 1; ++d) {
        if (d % 2 == 0) {
            // Upwards
            int r = d < M ? d : M - 1;
            int c = d - r;
            while (r >= 0 && c < N) {
                result.push_back(mat[r][c]);
                --r;
                ++c;
            }
        } else {
            // Downwards
            int c = d < N ? d : N - 1;
            int r = d - c;
            while (c >= 0 && r < M) {
                result.push_back(mat[r][c]);
                ++r;
                --c;
            }
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << endl;
    return 0;
}