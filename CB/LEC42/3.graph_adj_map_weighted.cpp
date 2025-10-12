/*
input:

5 6
A B 7
A C 1
B D 2
C D 9
C E 6
D E 5

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
    int n; int m;

    cin >> n >> m;

    map<char,vector<pair<char,int>>> adj;

    for(int i = 0; i < m; i++)
    {
        char u; char v; int w;
        cin >> u >> v >> w;
        // u--; v--; // do this if you want to take input as 0-based indexing.
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // comment this if directed graph
        
    }

    for(pair<char,vector<pair<char,int>>> p : adj)
    {
        char nodeLabel = p.first;
        vector<pair<char,int>> ngbList = p.second;

        cout << "ngb(" << nodeLabel << ") = ";
        for(pair<char,int> ngb: ngbList)
        {
            cout <<"(" << ngb.first << ","  << ngb.second << ")" << " ";
        }
        cout << endl;
    }
    
}