#include <bits/stdc++.h>
using namespace std;

////Recursion(Top-Down)

/* int fib(int n, vector<int>& dp){

if(n<=1) return n;

if(dp[n]!=-1) return dp[n];

return dp[n]= fib(n-2,dp)+fib(n-1,dp);
}

int main(){
int n=5;
vector<int> dp(n+1,-1);
cout<<fib(n,dp);
} */

//tc: O(n) linear pattern of recursion now that we are using memoization
//sc: O(n) + O(n) dp array and recursive stack 


//////TABULATION(Bottom-up)

/* int main(){
int n=5;
vector<int> dp(n+1);
dp[0]=0;
dp[1]=1;
for(int i=2;i<=n;i++){
    dp[i]=dp[i-2]+dp[i-1];
}
cout<< dp[n];
} */


//TC-O(n)
//SC-O(n) for the dp array(no recursive stack) 


int main(){
int n=5;
if(n<=1) return n;
int ans=-1;
int prev1=0;
int prev2=1;
for(int i=2;i<=n;i++){
    ans=prev1+prev2;
    prev1=prev2;
    prev2=ans;
}
cout<< ans;
}

//TC-O(n)
//SC-O(1)