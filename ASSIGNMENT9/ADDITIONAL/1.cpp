#include <bits/stdc++.h>
using namespace std;

void adjacencyList(int V, int E, vector<vector<int>>& adj) {
    // input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        // undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // print adjacency list
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int neigh : adj[i]) {
            cout << neigh << ", ";
        }
        cout << endl;
    }
}

void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
    visited[node] = 1;
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            dfs(neigh, adj, visited);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);   // adjacency list
    adjacencyList(V, E, adj);     // build graph

    vector<int> visited(V, 0);
    int components = 0;

    // count connected components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            components++;
            dfs(i, adj, visited);
        }
    }

    cout << components << endl;

    return 0;
}
