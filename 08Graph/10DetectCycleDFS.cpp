#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect a cycle using DFS
    bool dfs(int vertex, int parent, vector<int>& vis, vector<int> adj[]) {
        vis[vertex] = 1;

        for (auto it : adj[vertex]) {
            if (!vis[it]) {
                if (dfs(it, vertex, vis, adj)) return true;  // Return the result of the recursive call
            } 
            else if (it != parent) {  // If the adjacent node is visited and not the parent, there is a cycle
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);  // Initialize the visited array

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj)) return true;  // If a cycle is found, return true
            }
        }
        return false;  // If no cycle is found, return false
    }
};

int main() {
    // Hardcoded input
    int V = 5;  // Number of vertices
    int E = 5;  // Number of edges

    // Create an adjacency list for the graph
    vector<int> adj[V];
    
    // Hardcoded edges (for undirected graph)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1);  // This creates a cycle: 1-2-3-4-1
    adj[1].push_back(4);

    // Solution object
    Solution obj;
    
    // Check for cycle
    bool ans = obj.isCycle(V, adj);
    
    if (ans)
        cout << "Cycle detected!\n";
    else
        cout << "No cycle detected.\n";

    return 0;
}

//tc: tc of dfs - O(N + 2E)
//sc: queue +vis array -> O(N)