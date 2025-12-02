#include <bits/stdc++.h>
using namespace std;

// Prim's algorithm for MST using adjacency matrix (simple)
int primMST(int V, vector<vector<int>> &graph) {
    vector<int> key(V, INT_MAX);     // min weight edge to a vertex
    vector<bool> inMST(V, false);    // is vertex included
    key[0] = 0;                      // start from vertex 0

    int totalCost = 0;

    for (int i = 0; i < V; i++) {
        // pick minimum key vertex not in MST yet
        int u = -1;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        inMST[u] = true;
        totalCost += key[u];

        // update keys of neighbours
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalCost;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int cost = primMST(V, graph);
    cout << "Total MST cost = " << cost << endl;
    return 0;
}
