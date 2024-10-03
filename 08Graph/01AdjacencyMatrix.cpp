#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> printGraph(int V, vector<pair<int, int>> edges) {
    vector<vector<int>> graph(V);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

int main() {
    int V = 5;
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3},
        {1, 4},
        {3, 4}
    };

    vector<vector<int>> adj = printGraph(V, edges);

    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (auto it : adj[i]) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
