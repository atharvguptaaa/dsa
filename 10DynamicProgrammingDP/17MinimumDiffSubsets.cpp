#include<bits/stdc++.h>
using namespace std;
// Finds the minimum difference between two subsets of an array , given elemts of array are +ve.

int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for (auto it : nums) sum += it;

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    if (nums[0] <= sum) {
        dp[0][nums[0]] = true;
    }

    for (int ind = 1; ind < n; ind++) {
        for (int tgt   = 1; tgt <= sum; tgt++) {
            bool notTake = dp[ind - 1][tgt];
            bool take = false;
            if (nums[ind] <= tgt) {
                take = dp[ind - 1][tgt - nums[ind]];
            }
            dp[ind][tgt] = take || notTake;
        }
    }
    
    int minDif = INT_MAX;
    for (int i = 0; i <= sum / 2; i++) { //sum/2 because s2 takes care of other half
        if (dp[n - 1][i] == true) { //n-1th index finds the possibility of that sum in all of nums
            int s1 = i;
            int s2 = sum - i;
            minDif = min(minDif, abs(s2 - s1));
        }
    }
    return minDif;
}

int main() {
    vector<int> nums = {1, 6, 11, 5};
    int result = minimumDifference(nums);
    cout << "Minimum difference between two subsets: " << result << endl;
    return 0;
}