// Problem: Given an array of card points and an integer k, find the maximum score by picking k cards from either the start or end.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0;
        int rsum = 0;
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }
        int maxSum = lsum;
        int rIndex = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rIndex];
            rIndex--;
            maxSum = max(maxSum, lsum + rsum);
        }
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << sol.maxScore(cardPoints, k) << endl;
    return 0;
}
