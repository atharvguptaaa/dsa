#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;

            if (nums[low] <= nums[mid]) { // Left half is sorted
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else { // Right half is sorted
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;

    // Test case
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};  // Rotated sorted array
    int target = 0;  // Target value to find

    int result = obj.search(nums, target);

    cout << "Index of " << target << " is: " << result << endl;  // Output should be 4

    return 0;
}
