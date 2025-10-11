/*
input:

5 6
0 1
0 2
1 3
2 3
2 4
3 4

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{
    int n; int m;

    cin >> n >> m;

    vector<set<int>> adj(n);

    for(int i = 0; i < m; i++)
    {
        int u; int v;
        cin >> u >> v;
        // u--; v--; // do this if you want to take input as 0-based indexing.
        adj[u].insert(v);
        adj[v].insert(u); // comment this if directed graph
    }

    for(int i = 0; i < n; i++)
    {
        cout << "ngb(" << i << ") = ";
        for(int ngb: adj[i])
        {
            cout << ngb << " ";
        }
        cout << endl;
    }
    
}