#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// multisource bfs

vector<vector<int>> updateMatrixOptimised(const vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> distMat(m, vector<int>(n, INT_MAX));

    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({i, j});
                distMat[i][j] = 0;
            }
        }
    }

    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};

    while (!q.empty())
    {
        auto [cur_i, cur_j] = q.front();
        q.pop();

        for(int k = 0; k < 4; k++)
        {
            int nx = cur_i + dx[k];
            int ny = cur_j + dy[k];

            if(nx >= 0 and nx < m and ny >=0 and ny < n and distMat[nx][ny] == INT_MAX)
            {
                q.push({nx,ny});
                distMat[nx][ny] = distMat[cur_i][cur_j] + 1; 
            }

        }
    }

    return distMat;

}

int main()
{

    vector<vector<int>> mat = {{0,1,1,1,0},
                               {1,1,1,1,1},
                               {1,1,0,1,1},
                               {1,1,1,1,1},
                               {0,1,1,1,0}};

    vector<vector<int>> result = updateMatrixOptimised(mat);

    for(vector<int> i: result)
    {
        for(int j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}