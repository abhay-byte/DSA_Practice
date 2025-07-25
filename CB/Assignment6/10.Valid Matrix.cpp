#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> row(n), col(m);
    for (int i = 0; i < n; ++i)
    {
        cin >> row[i];
    }
    for (int j = 0; j < m; ++j)
    {
        cin >> col[j];
    }

    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int val = min(row[i], col[j]);
            mat[i][j] = val;
            row[i] -= val;
            col[j] -= val;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << mat[i][j];
            if (j != m - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}