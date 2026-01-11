
/*
16 16

0 2
0 3
1 3
1 4
2 5
3 5
3 6
4 6

7 9
8 9
9 10
9 11

12 13
12 14
13 15
14 15

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// time: O(V + 2E)
// space: V due to vis[] + v due to fn call stack = 2V ~ O(V)

void dfs(int cur, const vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[cur] = true;
    cout << cur << " ";

    for (int ngb : adj[cur])
    {
        if (!vis[ngb])
        {
            dfs(ngb, adj, vis);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);

    int numOfComponents = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            // make i as src and use dfs / bfs to traverse
            cout << "dfs(" << i << ") = ";
            dfs(i, adj, vis);
            cout << endl;
            numOfComponents++;
        }
    }

    cout << numOfComponents << endl;
}