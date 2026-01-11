
/*
4 4 

0 1
1 2
2 3
3 0

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// time: O(V + 2E)
// space: V due to vis[] + v due to fn call stack = 2V ~ O(V)

bool dfs(int cur, const vector<vector<int>> &adj, vector<bool>& stackState, vector<bool> &vis)
{
    vis[cur] = true;

    stackState[cur] = true;

    for(int ngb: adj[cur])
    {
        if(!vis[cur])
        {
            //ngb not yet visited
            if(dfs(ngb,adj,stackState,vis))
            {
                return true;
            }
        }
        else
        {
            //ngb is visited

            //check if cur to ngb has a directed edge is a back edge.

            //cur to ngb will be a backedge only when there is a directed path from ngb to cur

            if(stackState[ngb])
            {
                //ngb is present on the function call stack therefore there is 
                // a directed path from ngb to cur there the directed
                //edge from the cur to ngb is a backedge hence we have found a cycle.
                return true;
            }
        }
    }

    stackState[cur] = false;

    // no directed cycle in component of cur

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
    vector<bool> stackState(n, false); // tells if node i is present on the call stack

    int flag = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            // check if component of node i contains a cycle.
            cout << "dfs(" << i << ") = ";
            if (dfs(i, adj, stackState, vis))
            {
                cout << "Directed Cycle found" << endl;
                flag = true;
                break;
            }
            cout << endl;
        }
    }

    if (!flag)
    {
        cout << "Directed Cycle not found";
    }
}