#include <bits/stdc++.h>
using namespace std;

// Dijkstra using adjacency list
void dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int d = top.first;
        int u = top.second;

        if (d > dist[u]) continue; // ignore old entry

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << src << ": ";
    for (int i = 0; i < V; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});  // directed graph
    }

    dijkstra(V, adj, 0); // from source 0
    return 0;
}
