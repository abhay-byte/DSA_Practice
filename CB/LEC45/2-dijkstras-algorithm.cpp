/*
5 7 
0 1 10
0 2 5
1 2 3
1 3 1
2 3 9
2 4 2
2 4 8
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int s = 0; //assume source vertex to be zero

    vector<int> dis(n,INF);
    dis[s] = 0;

    vector<bool> expl(n,false);
    set<pair<int,int>> minHeap; //to track nodes that are not yet explored

    for(int i = 0; i < n; i++)
    {
        minHeap.insert({dis[i],i});        
    }

    //time: VlogV + ElogV ~ O((V+E)logV)
    //space: O(V) due to expl and minheap
    while(!minHeap.empty())
    {
        auto [dis_cur, cur] = *minHeap.begin();
        minHeap.erase(minHeap.begin());

        for(auto [ngb, edgeWt] : adj[cur])
        {
            if(!expl[ngb] and dis[ngb] > dis[cur] + edgeWt)
            {
                //edge to be relaxed, cur to ngb is tensed
                auto it = minHeap.find({dis[ngb],ngb});
                minHeap.erase(it);
                dis[ngb] = dis[cur] + edgeWt;
                minHeap.insert({dis[ngb],ngb});
            }
        }
        
        expl[cur] = true;
    }

    for(int i = 0; i < n; i++)
    {
        cout << "dis(" << i << ") = " << dis[i] << endl; 
    }
}
