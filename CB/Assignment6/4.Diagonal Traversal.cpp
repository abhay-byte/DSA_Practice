#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    vector<vector<int>> mat(M, vector<int>(N));
    for (auto& row : mat)
        for (auto& val : row)
            cin >> val;

    vector<int> result;
    for (int d = 0; d < M + N - 1; ++d) {
        int r, c;
        if (d % 2 == 0) {
            r = min(d, M - 1);
            c = d - r;
            while (r >= 0 && c < N)
                result.push_back(mat[r--][c++]);
        } else {
            c = min(d, N - 1);
            r = d - c;
            while (c >= 0 && r < M)
                result.push_back(mat[r++][c--]);
        }
    }

    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << (i + 1 < result.size() ? " " : "\n");
    }
    return 0;
}
