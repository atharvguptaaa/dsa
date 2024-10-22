#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // Initialize all nodes as uncolored (-1)
        queue<int> q;
        
        //to handle disconnected components
        for (int start = 0; start < n; start++) {
            if (color[start] == -1) {  // If the node hasn't been colored yet
                q.push(start);
                color[start] = 0;  // Start coloring the node with color 0

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                   
                    for (auto neighbor : graph[node]) {
                        if (color[neighbor] == -1) {  // If the neighbor hasn't been colored
                            q.push(neighbor);
                            color[neighbor] = !color[node];  // Assign opposite color
                        } else if (color[neighbor] == color[node]) {
                            // If the neighbor has the same color, it's not bipartite
                            return false;
                        }
                    }
                }
            }
        }
        return true;  // If no conflicts, the graph is bipartite
    }
};

int main() {
    Solution solution;
    
 
    vector<vector<int>> graph = {
        {},             // Node 0 (disconnected)
        {2, 4, 6},      // Node 1 is connected to nodes 2, 4, 6
        {1, 4, 8, 9},   // Node 2 is connected to nodes 1, 4, 8, 9
        {7, 8},         // Node 3 is connected to nodes 7, 8
        {1, 2, 8, 9},   // Node 4 is connected to nodes 1, 2, 8, 9
        {6, 9},         // Node 5 is connected to nodes 6, 9
        {1, 5, 7, 8, 9},// Node 6 is connected to nodes 1, 5, 7, 8, 9
        {3, 6, 9},      // Node 7 is connected to nodes 3, 6, 9
        {2, 3, 4, 6, 9},// Node 8 is connected to nodes 2, 3, 4, 6, 9
        {2, 4, 5, 6, 7, 8} // Node 9 is connected to nodes 2, 4, 5, 6, 7, 8
    };
    
    // Call the isBipartite function and print the result
    bool result = solution.isBipartite(graph);
    if (result) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}

//tc: tc of bfs - O(V + 2E)