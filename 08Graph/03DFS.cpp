#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int vis[], vector<int> adj[], vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);
    
    for (auto it : adj[node]) {    // Traverse all the unvisited neighbors of the current node
        if (!vis[it]) {
            dfs(it, vis, adj, ls);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> ls;
    int vis[V] = {0};
    int start = 0;
    
    dfs(start, vis, adj, ls);
    
    return ls;
}

int main() {
    int V = 5;
    
    vector<int> adj[V];
    
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);

    vector<int> result = dfsOfGraph(V, adj);
    cout<< "DFS traversal: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
