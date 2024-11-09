#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum cherries two robots can collect starting from (0,0) and (0,n-1)
// and moving to adjacent cells in each row until reaching the last row of the grid.

/* vector<vector<vector<int>>> dp;
int f(int i, int j1,int j2,vector<vector<int>>& grid, int m, int n){
        if(j1<0||j2<0||j1>=n||j2>=n){
            return -1e8;
        }
        if(i==m-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        //moves
        int maxi=INT_MIN;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
               if(j1==j2) maxi=max(maxi,grid[i][j1]+f(i+1,j1+d1,j2+d2,grid,m,n));
               else maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+d1,j2+d2,grid,m,n));
            }
        }
        return dp[i][j1][j2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(n,-1)));
        return f(0,0,n-1, grid,m,n);
    }
    //tc: O(MxNxN) x 9
    //sc: O(MxNxN) + O(M) dp arr+ rec stack */

//tabulation
/* int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    for(int j1=0;j1<n;j1++){
        for(int j2=0;j2<n;j2++){
            if(j1==j2) dp[m-1][j1][j2]=grid[m-1][j2];
            else dp[m-1][j1][j2]=grid[m-1][j1]+grid[m-1][j2];
        }
    }

    for(int i=m-2;i>=0;i--){
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){

                int maxi=INT_MIN;

    for(int d1=-1;d1<=1;d1++){
        for(int d2=-1;d2<=1;d2++){
            int value=0;
            if(j1==j2) value=grid[i][j1];
            else value= grid[i][j1]+grid[i][j2];

              if(j1+d1<0||j2+d2<0||j1+d1>=n||j2+d2>=n){
                continue;
              }
              else{
                maxi=max(maxi,value+dp[i+1][j1+d1][j2+d2]);
              }

        }
    }
        dp[i][j1][j2]=maxi;

            }
        }
    }
    return dp[0][0][n-1];
} 
//tc: O(MxNxN) x 9
//sc: O(MxNxN) */

//space optimized
int cherryPickup(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> prev(n, vector<int>(n, -1));
    for (int j1 = 0; j1 < n; j1++)
    {
        for (int j2 = 0; j2 < n; j2++)
        {
            if (j1 == j2)
                prev[j1][j2] = grid[m - 1][j2];
            else
                prev[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
        }
    }

    for (int i = m - 2; i >= 0; i--)
    {
        vector<vector<int>> cur(n, vector<int>(n, -1));
        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {

                int maxi = INT_MIN;

                for (int d1 = -1; d1 <= 1; d1++)
                {
                    for (int d2 = -1; d2 <= 1; d2++)
                    {
                        int value = 0;
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];

                        if (j1 + d1 < 0 || j2 + d2 < 0 || j1 + d1 >= n || j2 + d2 >= n)
                        {
                            continue;
                        }
                        else
                        {
                            maxi = max(maxi, value + prev[j1 + d1][j2 + d2]);
                        }
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        prev = cur;
    }
    return prev[0][n - 1];
}
//tc: O(MxNxN) x 9
//sc: O(NxN) 

int main()
{
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}};
    int result = cherryPickup(grid);
    cout << result;
    return -1;
}
