// Sort an array in ascending order using heap sort
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1; 
        int right = 2 * i + 2;
        if (left < n && nums[left] > nums[largest]) {
            largest = left;
        }
        if (right < n && nums[right] > nums[largest]) {
            largest = right;
        }
        if (largest != i) {
            swap(nums[largest], nums[i]);
            heapify(nums, n, largest);
        }
    }

    void heapSort(vector<int>& nums, int n) {
        //build a max-heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }
        //sort that max-heap
        for (int i = n - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        heapSort(nums, n);
        return nums;
    }
};

int main() {
    vector<int> nums = {4, 10, 3, 5, 1};
    Solution sol;
    vector<int> sorted = sol.sortArray(nums);
    for (int num : sorted) {
        cout << num << " ";
    }
    return 0;
}
