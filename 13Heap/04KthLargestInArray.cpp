// Program to find the kth largest element in an array using a max heap.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxheap(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            maxheap.pop();
        }
        return maxheap.top();
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution solution;
    cout << "The " << k << "th largest element is: " << solution.findKthLargest(nums, k) << endl;
    return 0;
}