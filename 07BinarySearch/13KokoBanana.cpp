#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long bananaCalc(int x, vector<int>& piles) {
        long long hours = 0;
        for (auto i : piles) {
            hours += (long long)(i + x - 1) / x;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxPile, ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = bananaCalc(mid, piles);

            if (hours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {30, 11, 23, 4, 20}; // Example test case
    int h = 6;
    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}
