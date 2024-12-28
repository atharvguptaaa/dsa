// Find the number of ways to partition an array into two subsets with a given difference 'd'.

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int f(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (index == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || target == arr[0]) return 1;
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

int countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    // If invalid conditions for partition
    if (sum < d || (sum - d) % 2 != 0) return 0;
    int s = (sum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(s + 1, -1));
    return f(n - 1, s, arr, dp);
}

int main() {
    vector<int> arr = {0,1, 1, 2, 3}; // Hardcoded array
    int d = 1;                     // Hardcoded target difference
    cout << countPartitions(arr, d) << endl; // Output the result
    return 0;
}
