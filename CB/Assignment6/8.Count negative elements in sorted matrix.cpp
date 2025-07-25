#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            cin >> mat[i][j];

    int count = 0;
    int row = 0, col = n - 1;
    while(row < m && col >= 0) {
        if(mat[row][col] < 0) {
            count += (col + 1);
            row++;
        } else {
            col--;
        }
    }
    cout << count << endl;
    return 0;
}