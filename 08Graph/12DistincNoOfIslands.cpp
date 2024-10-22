#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to perform DFS and track relative positions of island cells
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid, 
             vector<pair<int,int>>& vec, int row0, int col0) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Mark current cell as visited
        vis[r][c] = 1;
        
        // Store the relative position of the current cell compared to the starting cell (row0, col0)
        vec.push_back({r - row0, c - col0});
        
        // Arrays to represent the four possible directions (right, down, left, up)
        int a[] = {0, 1, 0, -1};
        int b[] = {1, 0, -1, 0};
        
        // Explore all four directions
        for (int i = 0; i < 4; i++) {
            int nr = r + a[i];  // new row
            int nc = c + b[i];  // new column

            // Check if the new cell is valid and part of the same island
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && !vis[nr][nc]) {
                dfs(nr, nc, vis, grid, vec, row0, col0);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        // Set to store the unique shapes of islands
        set<vector<pair<int, int>>> st;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the current cell is part of an island and hasn't been visited yet
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;  // Vector to store the shape of the current island
                    dfs(i, j, vis, grid, vec, i, j); 
                    st.insert(vec);  // Insert the island shape into the set
                }
            }
        }
        
        return st.size();
    }
};

int main() {
    // Example grid with islands
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 1, 1, 0, 0}
    };

    // Create a Solution object
    Solution sol;
    
    // Count and print the number of distinct islands
    cout << "Number of distinct islands: " << sol.countDistinctIslands(grid) << endl;

    return 0;
}


// tc: n x m x log(m x n) + n x m x 4 -> O(n xmxlog(nm))
      //outer    set_len      dfs
//sc: n x m + n x m   ->O(n x m)
      //set    vis