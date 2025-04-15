#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
//Graph Using STL (Adjacency List)
class Graph {
    unordered_map<int, list<int>> adj;  // adjacency list

public:
    // Add edge (undirected by default)
    void addEdge(int u, int v, bool isDirected = false) {
        adj[u].push_back(v);
        if (!isDirected) adj[v].push_back(u);
    }

    // Remove edge
    void removeEdge(int u, int v, bool isDirected = false) {
        adj[u].remove(v);
        if (!isDirected) adj[v].remove(u);
    }

    // Check if edge exists
    bool hasEdge(int u, int v) {
        for (int neighbor : adj[u]) {
            if (neighbor == v) return true;
        }
        return false;
    }

    // Traverse (print all edges)
    void printGraph() {
        for (auto &pair : adj) {
            cout << pair.first << ": ";
            for (int node : pair.second)
                cout << node << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.printGraph();  // Traverse

    cout << "Edge 1-3 exists? " << (g.hasEdge(1, 3) ? "Yes" : "No") << endl;

    g.removeEdge(1, 3);
    g.printGraph();

    return 0;
}

//Graph Traversal Using BFS & DFS

void BFS(unordered_map<int, list<int>> &adj, int start) {
    set<int> visited;
    queue<int> q;

    visited.insert(start);
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
}

