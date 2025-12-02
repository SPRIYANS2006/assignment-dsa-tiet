#include <bits/stdc++.h>
using namespace std;


void buildGraph(int V, int E, vector<vector<int>> &adj) {
    adj.assign(V, {}); 
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;         
        adj[u].push_back(v);
        adj[v].push_back(u);    // because graph is undirected
    }
}

// BFS function
void bfs(int start, vector<vector<int>> &adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                visited[neigh] = true;
                q.push(neigh);
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj;
    buildGraph(V, E, adj);

    bfs(0, adj);  
    return 0;
}
