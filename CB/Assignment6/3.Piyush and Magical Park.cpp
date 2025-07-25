#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<vector<char>> park(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> park[i][j];

    bool success = true;
    for (int i = 0; i < n && success; ++i) {
        for (int j = 0; j < m; ++j) {
            char cell = park[i][j];
            if (cell == '.') {
                s -= 2;
            } else if (cell == '*') {
                s += 5;
            } else if (cell == '#') {
                break;
            }
            if (j != m - 1) s--;
            if (s < k) {
                success = false;
                break;
            }
        }
    }
    if (success && s >= k) {
        cout << "Yes" << endl << s << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
