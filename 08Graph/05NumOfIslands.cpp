#include <iostream>
#include <vector>

using namespace std;

void dfs(pair<int,int>& nodePair, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int f = nodePair.first;
    int s = nodePair.second;
    vis[f][s] = 1;

    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++) {
        int fNew = f + row[k];
        int sNew = s + col[k];

        nodePair = {fNew, sNew};
        if (fNew >= 0 && fNew < m && sNew >= 0 && sNew < n && grid[fNew][sNew] == '1' && !vis[fNew][sNew]) {
            dfs(nodePair, vis, grid);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    pair<int, int> nodePair;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 0 && grid[i][j] == '1') {
                count++;
                nodePair = {i, j};
                dfs(nodePair, vis, grid);
            }
        }
    }
    return count;
}

int main() {
    // Hardcoded input: a grid of land ('1') and water ('0')
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int result = numIslands(grid);
    cout << "Number of islands: " << result << endl;

    return 0;
}
