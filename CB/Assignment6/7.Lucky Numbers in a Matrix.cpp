#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    vector<int> rowMin(m, INT_MAX);
    vector<int> colMax(n, INT_MIN);

    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            rowMin[i] = min(rowMin[i], matrix[i][j]);

    for(int j = 0; j < n; ++j)
        for(int i = 0; i < m; ++i)
            colMax[j] = max(colMax[j], matrix[i][j]);

    vector<int> luckyNumbers;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j])
                luckyNumbers.push_back(matrix[i][j]);
        }
    }

    for(int num : luckyNumbers)
        cout << num << " ";
    cout << endl;
    return 0;
}