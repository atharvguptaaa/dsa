/* 34. Find First and Last Position of Element in Sorted Array.
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity. */
#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans = {-1, -1};
    int start = bS(nums, target, true);
    int end = bS(nums, target, false);
    ans[0] = start;
    ans[1] = end;
    return ans;
}

int bS(vector<int>& nums, int target, bool wantStartIndex) {
    int ans = -1;
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            ans = mid;
            if (wantStartIndex) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "Start: " << result[0] << ", End: " << result[1] << endl;
    return 0;
}
