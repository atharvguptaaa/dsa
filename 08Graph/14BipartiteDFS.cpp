#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph) {
        color[node] = col;  // Color the current node
        col = !col;  // Switch to the opposite color for the next node
        
        for (auto it : graph[node]) {
            if (color[it] == -1) {  // If the neighbor is not colored
                if (!dfs(it, col, color, graph)) {
                    return false;  // Return false if a conflict is found
                }
            } else if (color[it] == color[node]) {  // If the neighbor has the same color
                return false;  // Conflict found, return false
            }
        }
        return true;  // No conflict found, the component is bipartite
    }

    // Function to check if the entire graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); 
        
        // Check every node 
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {  // If the node is not yet colored
                if (!dfs(i, 0, color, graph)) {  // Start DFS with color 0
                    return false;  
                }
            }
        }
        return true;  
    }
};

int main() {
    // Hardcoded test case
    vector<vector<int>> graph = {
        {},             // Node 0
        {2, 4, 6},      // Node 1
        {1, 4, 8, 9},   // Node 2
        {7, 8},         // Node 3
        {1, 2, 8, 9},   // Node 4
        {6, 9},         // Node 5
        {1, 5, 7, 8, 9},// Node 6
        {3, 6, 9},      // Node 7
        {2, 3, 4, 6, 9},// Node 8
        {2, 4, 5, 6, 7, 8} // Node 9
    };

    Solution sol;
    bool result = sol.isBipartite(graph);

    if (result) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}

//tc: tc of dfs - O(V + 2E)