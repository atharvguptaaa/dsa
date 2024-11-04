// Given an array of integers representing house values, find the maximum amount of money 
// that can be robbed without robbing two adjacent houses.

#include <bits/stdc++.h>
using namespace std;

//recursion
/* int f(int n, vector<int>& dp, vector<int>& nums) {
    if (n == 0) return dp[0]= nums[0];
    if (n < 0) return 0;
    if (dp[n] != -1) return dp[n];
    int pick = nums[n] + f(n - 2, dp, nums);
    int noPick = 0 + f(n - 1, dp, nums);
    return dp[n] = max(pick, noPick);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    return f(n - 1, dp, nums);
} */

//tabulation
/* int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=dp[i-2];
            int noPick=dp[i-1];
            dp[i]=max(pick,noPick);
        }
        return dp[n-1];
    } */

   //space optimization
   int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        int prev=nums[0];
        int prev2=0;
        int curi=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i]+prev2;
            int noPick=prev;
            curi=max(pick,noPick);

            prev2=prev;
            prev=curi;
        }
        return curi;   
    }

int main() {
    vector<int> nums = {100, 200, 300, 100};
    cout << rob(nums) << endl;  // Example usage
    return 0;
}
