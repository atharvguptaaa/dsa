// Finds the minimum path sum from the top to the bottom of a triangle
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//recursion
/* vector<vector<int>> dp;

int f(int i, int j, vector<vector<int>>& triangle) {
    int n = triangle.size();
    if (i == n - 1) return triangle[i][j];
    if (dp[i][j] != -1) return dp[i][j];
    int down = f(i + 1, j, triangle) + triangle[i][j];
    int dgnl = f(i + 1, j + 1, triangle) + triangle[i][j];
    return dp[i][j] = min(down, dgnl);
}

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    dp.assign(n, vector<int>(n, -1));
    return f(0, 0, triangle);
}
//tc: O(NxN)
//sc: O(N)+O(NxN) recursive stack + DP array */

//tabulation
/* int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        //base case
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        //moves
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=dp[i+1][j]+triangle[i][j];
                int dgnl=dp[i+1][j+1]+triangle[i][j];
                dp[i][j]=min(down,dgnl);
            }
        }
        return dp[0][0];
    } 
    //tc: O(NxN)
//sc: O(NxN) DP array */

//space optimization
   int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> prev(n);
        //base case
        for(int i=0;i<n;i++){
            prev[i]=triangle[n-1][i];
        }
        //moves
        for(int i=n-2;i>=0;i--){
            vector<int> cur(i+1);
            for(int j=i;j>=0;j--){
                int down=prev[j]+triangle[i][j];
                int dgnl=prev[j+1]+triangle[i][j];
                cur[j]=min(down,dgnl);
            }
            prev=cur;
        }
        return prev[0];
    }
//tc: O(NxN)
//sc: O(2N) prev and cur 

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    cout << "Minimum Path Sum: " << minimumTotal(triangle) << endl;
    return 0;
}
