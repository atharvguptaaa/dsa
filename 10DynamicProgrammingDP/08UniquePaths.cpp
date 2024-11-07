#include <iostream>
#include <vector>
using namespace std;

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner from the top left corner.
vector<vector<int>> dp;

//Memoization
/* int f(int i, int j) {
    if (i == 0 && j == 0) return 1;
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int up = f(i - 1, j);
    int left = f(i, j - 1);
    dp[i][j] = up + left;
    return dp[i][j];
}

int uniquePaths(int m, int n) {
    dp.assign(m, vector<int>(n, -1));
    return f(m - 1, n - 1);
} */

//tc-O(2^mn)
//sc- recursive stack=path length= O(m-1+n-1)   + O(mn) for dp array

//Tabulation
  /* int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(i==0&&j==0) {dp[i][j]=1; continue;}  
              int up=0,left=0;  
              if(i>0) up=dp[i-1][j];
              if(j>0) left=dp[i][j-1];
              
              dp[i][j]=up+left;
            }
        }
        
        return dp[m-1][n-1];
    } */
    // tc:O(mn) 
    //sc: O(mn)no recursive stack space

//space optimization
int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++){
              if(i==0&&j==0) {cur[j]=1; continue;}  
              int up=0,left=0;  
              if(i>0) up=prev[j];
              if(j>0) left=cur[j-1];
              
              cur[j]=up+left;
            }
            prev=cur;
        }
        
        return prev[n-1];
    }
//sc- O(n)


int main() {
    int m = 3, n = 3; // Hardcoded grid size
    cout << "Number of unique paths in a " << m << "x" << n << " grid: " << uniquePaths(m, n) << endl;
    return 0;
}