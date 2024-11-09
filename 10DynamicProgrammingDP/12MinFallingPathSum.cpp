#include <bits/stdc++.h>
using namespace std;
// min path sum from any cell in first row to any cell in last row of nxn matrix

// recursion
/* vector<vector<int>> dp;
int f(int i, int j, vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (i == n - 1) return matrix[i][j];
    if (j < 0 || j >= n) return 1e9; // Ensures index j is in bounds
    if (dp[i][j] != -1) return dp[i][j];

    int down = f(i + 1, j, matrix) + matrix[i][j];
    int dgright = (j < n - 1) ? f(i + 1, j + 1, matrix) + matrix[i][j] : INT_MAX;
    int dgleft = (j > 0) ? f(i + 1, j - 1, matrix) + matrix[i][j] : INT_MAX;

    return dp[i][j] = min({down, dgleft, dgright});
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    dp.assign(n, vector<int>(n, -1));
    int result = INT_MAX;

    for (int i = 0; i < n; i++) {
        result = min(result, f(0, i, matrix));
    }

    return result;
}
//tc-O(N x N) + O(N) recursion + last for loop
//sc-O(NxN) +O(N) dp arry+ rec stack space
*/

// tabulation
/*  int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n));
     //base case
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        //moves
        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                 int dgright=INT_MAX;
    int dgleft=INT_MAX;
    int down = dp[i + 1][j] + matrix[i][j];
    if(j<n-1)dgright = dp[i + 1][j + 1] + matrix[i][j];
    if(j>0)dgleft = dp[i + 1][j-1] + matrix[i][j];
    dp[i][j] = min({down, dgleft, dgright});
            }
        }
        int result=INT_MAX;
        for (int i = 0; i < n; i++) {
        result = min(result, dp[0][i]);
             }

    return result;

    }
    //tc-O(N x N) + O(N) recursion + last for loop
//sc-O(NxN) dp array
 */

// space opt
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<int> prev(n);
    // base case
    for (int i = 0; i < n; i++)
    {
        prev[i] = matrix[n - 1][i];
    }
    // moves
    for (int i = n - 2; i >= 0; i--)
    {
        vector<int> cur(n);
        for (int j = n - 1; j >= 0; j--)
        {
            int dgright = INT_MAX;
            int dgleft = INT_MAX;
            int down = prev[j] + matrix[i][j];
            if (j < n - 1)
                dgright = prev[j + 1] + matrix[i][j];
            if (j > 0)
                dgleft = prev[j - 1] + matrix[i][j];
            cur[j] = min({down, dgleft, dgright});
        }
        prev = cur;
    }
    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        result = min(result, prev[i]);
    }

    return result;
}
//tc-O(N x N) + O(N) recursion + last for loop
//sc-O(2N) prev and cur

int main()
{
    vector<vector<int>> matrix = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}};

    int minSum = minFallingPathSum(matrix);
    cout << minSum;
    return -1;
}
