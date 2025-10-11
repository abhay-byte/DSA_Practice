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

using namespace std;

int main()
{
    int n; int m;

    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++)
    {
        int u; int v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // comment this if directed graph
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