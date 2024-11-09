// Calculates the minimum path sum from the top-left to bottom-right of a grid
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* vector<vector<int>> dp;
int f(int i, int j, vector<vector<int>>& grid) {
    if (i == 0 && j == 0) return grid[0][0];
    if (i < 0 || j < 0) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j]; 
    int up = f(i - 1, j, grid) + grid[i][j];
    int left = f(i, j - 1, grid) + grid[i][j];
    return dp[i][j]=min(up, left);
}
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    dp.assign(m,vector<int>(n,-1));
    return f(m - 1, n - 1, grid);
} */

//tabulation
/* int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) continue;
                int up=INT_MAX;
                int left=INT_MAX;
                if(i>0)up=dp[i-1][j]+grid[i][j];
                if(j>0)left=dp[i][j-1]+grid[i][j];

                dp[i][j]=min(up,left);
            }
        }
        return dp[m-1][n-1];
    } */
   
   
// space optimization
int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>prev(n);
        for(int i=0;i<m;i++){
            vector<int> cur(n);
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                     cur[j]=grid[0][0];
                     continue;
                }
                int up=INT_MAX;
                int left=INT_MAX;
                if(i>0)up=prev[j]+grid[i][j];
                if(j>0)left=cur[j-1]+grid[i][j];

                cur[j]=min(up,left);
            }
            prev=cur;
        }
        return prev[n-1];
    }



int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    cout << "Minimum Path Sum: " << minPathSum(grid) << endl;
    return 0;
}
