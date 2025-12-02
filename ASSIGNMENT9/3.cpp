#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};


int findParent(int x, vector<int> &parent) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x], parent); // path compression
}

void unionSets(int a, int b, vector<int> &parent, vector<int> &rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

// Kruskal MST function
int kruskalMST(int V, vector<Edge> &edges) {
    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<int> parent(V), rank(V, 0);
    for (int i = 0; i < V; i++) parent[i] = i;

    int mstCost = 0;

    cout << "Edges in MST:\n";

    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            mstCost += e.w;
            cout << e.u << " - " << e.v << " (w=" << e.w << ")\n";
            unionSets(e.u, e.v, parent, rank);
        }
    }
    return mstCost;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int cost = kruskalMST(V, edges);
    cout << "Total MST cost = " << cost << endl;
    return 0;
}
