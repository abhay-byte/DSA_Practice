
/*
3 3

0 1
0 2
1 2

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// time: O(V + 2E)
// space: V due to vis[] + v due to fn call stack = 2V ~ O(V)

bool dfs(int cur, int par, const vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[cur] = true;

    for (int ngb : adj[cur])
    {
        if (!vis[ngb])
        {
            // ngb is not yet visited
            if (dfs(ngb, cur, adj, vis))
            {
                // found a cycle in the sub component of ngb
                // therefore you have found a cycle in cur component
                return true;
            }
        }
        else
        {
            // ngb already visited

            // check cur->ngb is a backedge or not

            if (ngb != par)
            {
                // cur->ngb is a backedge we have found a cycle
                // in component of cur
                return true;
            }
        }
    }

    // no cycle in component of cur

    return false;
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

    int flag = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            // check if component of node i contains a cycle.
            cout << "dfs(" << i << ") = ";
            if (dfs(i, -1, adj, vis))
            {
                cout << "Cycle found" << endl;
                flag = true;
                break;
            }
            cout << endl;
        }
    }

    if (!flag)
    {
        cout << "Cycle not found";
    }
}