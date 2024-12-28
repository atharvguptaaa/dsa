// Given an array of integers and a target sum, find the number of subsets in the array that sum up to the target.

#include <iostream>
#include <vector>
using namespace std;

//memoization
/* 
    int f(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base cases
        if (index == 0) {
            if (target == 0 && arr[0] == 0) return 2; // Special case: {∅}, {0}
            if (target == 0 || target == arr[0]) return 1; // {∅} or {arr[0]}
            return 0;
        }

    
        if (dp[index][target] != -1) return dp[index][target];


        int notTake = f(index - 1, target, arr, dp);

        int take = 0;
        if (target >= arr[index]) {
            take = f(index - 1, target - arr[index], arr, dp);
        }

        return dp[index][target] = take + notTake;
    }
        
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(n - 1, target, arr, dp);
    }
 */

int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1));

    for (int tar = 0; tar <= target; tar++) {
    if (tar == 0 && arr[0] == 0)
        dp[0][tar] = 2;  // Special case: 2 subsets {∅, {0}}
    else if (tar == 0 || tar == arr[0])
        dp[0][tar] = 1;  // Either {∅} or {arr[0]} forms the target
    else
        dp[0][tar] = 0;  // Target cannot be achieved
}


    for (int ind = 1; ind < n; ind++) {
        for (int tar = 0; tar <= target; tar++) {
            int notTake = dp[ind - 1][tar];
            int take = 0;
            if (tar >= arr[ind]) take = dp[ind - 1][tar - arr[ind]];
            dp[ind][tar] = take + notTake;
        }
    }

    return dp[n - 1][target];
}


//Space Optimized
/* int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>prev(target+1);
        
        for(int t=0; t<=target;t++){
            if(t==0 && arr[0]==0) 
                prev[t]= 2;
            else if(t==0 || arr[0]==t)
                prev[t]= 1;
            else
                prev[t]= 0;
        }
        
        for(int ind=1;ind<n;ind++){
            vector<int> cur(target+1);
            for(int tar=0;tar<=target;tar++){
                int notTake=prev[tar];
                int take=0;
                if(tar>=arr[ind]) take=prev[tar-arr[ind]];
                
                cur[tar]=take+notTake;
            }
            prev=cur;
        }
        return prev[target];
    }
}; */

int main() {
    vector<int> arr = {1, 2, 3, 3,0}; // Hardcoded array
    int target = 6;                // Hardcoded target sum
    cout << perfectSum(arr, target) << endl; // Output the result
    return 0;
}
