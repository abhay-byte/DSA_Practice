/*
input:

5 6
A B
A C
B D
C D
C E
D E

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int n; int m;

    cin >> n >> m;

    map<char,vector<char>> adj;

    for(int i = 0; i < m; i++)
    {
        char u; char v;
        cin >> u >> v;
        // u--; v--; // do this if you want to take input as 0-based indexing.
        adj[u].push_back(v);
        adj[v].push_back(u); // comment this if directed graph
    }

    for(pair<char,vector<char>> p : adj)
    {
        char nodeLabel = p.first;
        vector<char> ngbList = p.second;

        cout << "ngb(" << nodeLabel << ") = ";
        for(char ngb: ngbList)
        {
            cout << ngb << " ";
        }
        cout << endl;
    }
    
}