#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
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
};

int main() {
    int V = 5;  //number of vertices
    int E = 6;  //number of edges
    
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3},
        {1, 4},
        {3, 4}
    };  // Hardcoded edges
    
    Solution obj;
    vector<vector<int>> adj = obj.printGraph(V, edges);
    
    cout << "Adjacency List:" << endl;
    for (int i = 0; i < V; i++) {
        sort(adj[i].begin(), adj[i].end());
        cout << i << ": ";
        for (auto it : adj[i])
            cout << it << " ";
        cout << endl;
    }
    
    return 0;
}
