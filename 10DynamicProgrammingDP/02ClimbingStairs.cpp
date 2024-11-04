/* You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? */

#include<bits/stdc++.h>
using namespace std;

//Memoization
 /* int f(int n,vector<int>&dp){
        if(n<=1) return dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        int left=f(n-1,dp);
        int right=f(n-2,dp);
        return dp[n]=left+right;
    } */

/* int main()
{
  int n=10;  
  vector<int> dp(n+1,-1);
  cout<< f(n,dp);
} */

////TABULATION


/*     int main() {
        int n=10;
       vector<int> dp(n+1);
       dp[0]=dp[1]=1;
       
       for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
       }
       cout<< dp[n];

    } */


////SPACE OPTIMIZATION


        int main() {
        int n=10;

       int prev1=1;
       int prev2=1;
       int ans=1;

       for(int i=2;i<=n;i++){
       ans=prev1+prev2;
       prev1=prev2;
       prev2=ans; 
       }
       cout<< ans;

    } 