#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        int freshCount = 0;

        // Initialize queue with all initially rotten oranges and mark them visited
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {   
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        int tm = 0;  // Maximum time to rot all oranges
        int cnt = 0; // Count of rotten oranges

        // BFS to rot adjacent fresh oranges
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int t = q.front().second;
            q.pop();
            tm = t;

            // Check all four directions
            for (int k = 0; k < 4; k++) {
                int inew = i + row[k];
                int jnew = j + col[k];
                
                if (inew >= 0 && inew < m && jnew >= 0 && jnew < n && vis[inew][jnew] == 0 && grid[inew][jnew] == 1) {
                    q.push({{inew, jnew}, t + 1});
                    vis[inew][jnew] = 2;
                    cnt++; // Count this newly rotted orange
                }
            }
        }

        // If not all fresh oranges were rotten, return -1
        if (cnt != freshCount) return -1;

        // Return the total time taken to rot all oranges
        return tm;
    }
};

int main() {
    // Test case
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 2, 1}
    };

    Solution sol;
    int result = sol.orangesRotting(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;
    return 0;
}
