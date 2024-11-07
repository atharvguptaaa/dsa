#include <bits/stdc++.h>
using namespace std;

// Function to find the peak element
int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int main() {
    // Test case
    vector<int> nums = {1, 2, 3, 2};
    
    // Call the function and display the peak index
    int peakIndex = findPeakElement(nums);
    cout << "Peak element is at index: " << peakIndex << endl;

    return 0;
}
