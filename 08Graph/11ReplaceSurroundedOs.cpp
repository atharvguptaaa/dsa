#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // DFS to mark all 'O's connected to boundary 'O's as visited
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& board ){
        int m = board.size();
        int n = board[0].size();
        vis[r][c] = 1; // mark the cell as visited
        
        // Possible directions for traversal (up, right, down, left)
        int a[] = {0, 1, 0, -1};
        int b[] = {1, 0, -1, 0};
        
        for(int i = 0; i < 4; i++){
            int nr = r + a[i];
            int nc = c + b[i];

            // If the new row and column are valid and unvisited, continue DFS
            if(nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'O' && !vis[nr][nc]){
                dfs(nr, nc, vis, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m == 0 || n == 0) return; // Edge case: empty board

        // Visited matrix to keep track of cells already processed
        vector<vector<int>> vis(m, vector<int>(n, 0)); 

        // Traverse the boundary cells: left and right boundary columns
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, vis, board); // Left boundary
            }
            if(board[i][n-1] == 'O'){
                dfs(i, n-1, vis, board); // Right boundary
            }
        }

        // Traverse the boundary cells: top and bottom boundary rows
        for(int i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                dfs(0, i, vis, board); // Top boundary
            }
            if(board[m-1][i] == 'O'){
                dfs(m-1, i, vis, board); // Bottom boundary
            }
        }

        // Convert non-boundary 'O's to 'X', keeping boundary-connected 'O's unchanged
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X'; // Non-boundary 'O' to 'X'
                }
            }
        }
    }
};

// Driver code to test the Solution class
int main() {
    Solution obj;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    // Apply the solve function
    obj.solve(board);

    // Print the resulting board
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }

    return 0;
}

//Each cell in the matrix is visited at most once. Since there are m×n cells in the matrix, the DFS traverses all of them.
//tc: O(m x n) for dfs + O(m+n) for outer loops -> O(m x n)
//sc: O(m x n) for vis arr and O(m x n) worst case for recursive call stack -> O(m x n)