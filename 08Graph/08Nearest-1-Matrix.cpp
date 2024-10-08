#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    
    vector<vector<int>> vis(m, vector<int>(n, 0)); // Visited matrix
    vector<vector<int>> dist(m, vector<int>(n, 0)); // Distance matrix
    queue<pair<pair<int, int>, int>> q; // BFS queue to store {{row, col}, steps}

    // Initialize the queue with all cells containing 1 and mark them as visited
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {   
                q.push({{i, j}, 0}); // Push 1's with initial distance 0
                vis[i][j] = 1;    // Mark as visited
            }
        }    
    }

    // Directions array for moving up, right, down, and left
    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    // BFS traversal
    while (!q.empty()) {
        int i = q.front().first.first;
        int j = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[i][j] = steps; // Update the distance of the current cell

        // Check all 4 possible directions
        for (int k = 0; k < 4; k++) {
            int inew = i + row[k];
            int jnew = j + col[k];

            // Check if the new cell is valid and unvisited
            if (inew >= 0 && inew < m && jnew >= 0 && jnew < n && vis[inew][jnew] == 0) {
                q.push({{inew, jnew}, steps + 1}); // Push the new cell with updated steps
                vis[inew][jnew] = 1; // Mark the new cell as visited
            }
        }
    }

    return dist; // Return the distance matrix
}

int main() {
    vector<vector<int>> mat = {
        {0, 0, 1},
        {0, 1, 0},
        {1, 0, 0}
    };

    vector<vector<int>> result = updateMatrix(mat);

    cout << "Distance Matrix:" << endl;
    for (const auto& row : result) {
        for (int x : row) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

//tc- n x m + n x m x 4 -> O(n x m)
//sc= O(n x m) for the queue and vis array
