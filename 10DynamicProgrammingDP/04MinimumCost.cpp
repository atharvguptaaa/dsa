/*
Find the minimum cost to reach the last position in `arr` from the first.
You can jump up to `k` positions, with jump cost `abs(arr[i] - arr[j])`.
*/
#include<bits/stdc++.h>
using namespace std;

int minimizeCost(int k, vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int jump = dp[i - j] + abs(arr[i] - arr[i - j]);
                minCost = min(jump, minCost);
            }
        }
        dp[i] = minCost;
    }
    return dp[n - 1];
}

int main() {
    int k = 2;
    vector<int> arr = {30, 50, 90, 10, 60, 50};
    cout << minimizeCost(k, arr) << endl;
    return 0;
}
