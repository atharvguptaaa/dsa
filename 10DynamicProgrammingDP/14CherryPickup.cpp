#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Given a grid with cherries and thorns, two players start at the top-left and try to collect the maximum number of cherries. They can only move right or down and meet at the bottom-right. They collect cherries along the way but avoid cells with thorns (-1). Each cherry cell can be collected only once, even if both players meet at the same cell.

vector<vector<vector<int>>> dp;

int f(int r1, int r2, int c1, vector<vector<int>>& grid, int n) {
    int c2 = r1 + c1 - r2;
    if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
        return -1e8;
    }
    if (dp[r1][r2][c1] != -1) return dp[r1][r2][c1];

    if (r1 == n - 1 && c1 == n - 1) return grid[r1][c1];

    int value = 0;
    if (r1 == r2 && c1 == c2) value += grid[r1][c1];
    else value += grid[r1][c1] + grid[r2][c2];

    int a = f(r1 + 1, r2 + 1, c1, grid, n);
    int b = f(r1, r2, c1 + 1, grid, n);
    int c = f(r1 + 1, r2, c1, grid, n);
    int d = f(r1, r2 + 1, c1 + 1, grid, n);

    value += max({a, b, c, d});
    return dp[r1][r2][c1] = value;
}

int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    dp.assign(n, vector<vector<int>>(n, vector<int>(n, -1)));
    return max(0, f(0, 0, 0, grid, n));
}

int main() {
    vector<vector<int>> grid = {
        // {1, 1, -1},
        // {1, -1, 1},
        // {-1, 1, 1}
        {3,1,1},
        {2,5,1},
        {1,5,5}
    };
    cout << cherryPickup(grid) << endl;
    return 0;
}
