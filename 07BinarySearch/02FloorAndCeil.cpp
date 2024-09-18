#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find floor of x
    int findFloor(vector<long long> &v, long long n, long long x) {
        long long ans = -1;
        long long low = 0, high = n - 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (v[mid] <= x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    // Function to find ceil of x
    int findCeil(vector<long long> &v, long long n, long long x) {
        long long ans = -1;
        long long low = 0, high = n - 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (v[mid] >= x) {
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
    // Test case
    vector<long long> v = {1, 2, 4, 6, 8, 10};
    long long x = 5;
    long long n = v.size();

    Solution obj;

    // Finding floor
    int floorResult = obj.findFloor(v, n, x);
    if (floorResult == -1) {
        cout << "No floor exists for " << x << endl;
    } else {
        cout << "Floor of " << x << " is at index " << floorResult << " (value: " << v[floorResult] << ")" << endl;
    }

    // Finding ceil
    int ceilResult = obj.findCeil(v, n, x);
    if (ceilResult == -1) {
        cout << "No ceil exists for " << x << endl;
    } else {
        cout << "Ceil of " << x << " is at index " << ceilResult << " (value: " << v[ceilResult] << ")" << endl;
    }

    return 0;
}
