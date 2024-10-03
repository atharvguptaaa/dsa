#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<int>>& adj) {
    vis[node] = 1;

    for (int it = 0; it < adj[node].size(); it++) {
        if (adj[node][it] == 1 && !vis[it]) {
            dfs(it, vis, adj);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int provinces = 0;
    int V = isConnected.size();
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            provinces++;
            dfs(i, vis, isConnected);
        }
    }
    return provinces;
}

int main() {
    // Hardcoded input
    vector<vector<int>> isConnected = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    int result = findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl;

    return 0;
}
