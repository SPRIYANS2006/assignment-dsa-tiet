#include <bits/stdc++.h>
using namespace std;

// Build adjacency list
void buildGraph(int V, int E, vector<vector<int>> &adj) {
    adj.assign(V, {});
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// DFS helper function (recursive)
void dfsUtil(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfsUtil(neigh, adj, visited);
        }
    }
}

void dfs(int start, vector<vector<int>> &adj) {
    int V = adj.size();
    vector<bool> visited(V, false);

    cout << "DFS Traversal: ";
    dfsUtil(start, adj, visited);
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj;
    buildGraph(V, E, adj);

    dfs(0, adj);  
    return 0;
}
