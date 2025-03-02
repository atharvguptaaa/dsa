// Program to find the longest subarray of 1s with at most k flips
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//O(2n)
/* class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0, zeroCount = 0;
        int l = 0, r = 0;

        while (r < n) {  
            if (nums[r] == 0) {
                zeroCount++;
            }
            while (zeroCount > k) { //this second loop causes O(2n)
                if (nums[l] == 0) {
                    zeroCount--;
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
}; */

//O(n)
class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n=nums.size();
            int maxLen=0,zeroCount=0;
            int l=0,r=0;
    
            while(r<n){
                if(nums[r]==0){
                    zeroCount++;
                }
                if(zeroCount>k){
                    if(nums[l]==0){
                        zeroCount--;
                    }
                      l++;
                }
                else{
                maxLen=max(maxLen,r-l+1);
                }
                r++;
            }
            return maxLen;
        }
    };


int main() {
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1}; // Hardcoded value
    int k = 2;
    Solution sol;
    int result = sol.longestOnes(nums, k);
    cout << "The longest subarray of 1s with at most " << k << " flips is: " << result << endl;
    return 0;
}
