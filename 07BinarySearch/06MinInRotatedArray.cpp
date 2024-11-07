#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = INT_MAX;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        //if search space is sorted
        if(nums[low]<=nums[high]){
            ans=min(ans,nums[low]);
            break;
        }

        // If the left half is sorted (low to mid)
        if (nums[low] <= nums[mid]) {
            ans = min(ans, nums[low]);
            low = mid + 1;
        }
        // If the right half is sorted (mid to high)
        else {
            ans = min(ans, nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    // Hardcoded rotated sorted array
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    
    // Find minimum in rotated sorted array
    int minElement = findMin(nums);
    
    cout << "The minimum element is: " << minElement << endl;
    
    return 0;
}

//tc- O(log N)