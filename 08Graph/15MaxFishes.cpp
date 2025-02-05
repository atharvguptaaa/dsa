// LC2658- Find the maximum number of fish that can be collected by traversing connected non-zero cells in a grid.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vis[i][j] = 1;
        int fishCount = grid[i][j];
        int row[] = {0, 1, -1, 0};
        int col[] = {1, 0, 0, -1};
        for (int k = 0; k < 4; k++) {
            int newi = i + row[k];
            int newj = j + col[k];
            if (newi >= 0 && newi < m && newj >= 0 && newj < n && !vis[newi][newj] && grid[newi][newj] != 0) {
                fishCount += dfs(newi, newj, vis, grid);
            }
        }
        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && vis[i][j] == 0) {
                    res = max(res, dfs(i, j, vis, grid));
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> grid = {
        {1, 2, 0},
        {0, 3, 4},
        {5, 0, 6}
    };
    Solution solution;
    cout << solution.findMaxFish(grid) << endl;
    return 0;
}
