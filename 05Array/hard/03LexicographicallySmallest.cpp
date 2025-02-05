// Given an array and a limit, group elements such that adjacent elements in each group differ by at most 'limit',
// then rearrange elements to obtain the lexicographically smallest possible array while maintaining group constraints.

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        vector<deque<int>> list;
        unordered_map<int, int> map;
        int groupIndex = 0;
        
        list.push_back(deque<int>());
        list[groupIndex].push_back(temp[0]);
        map[temp[0]] = groupIndex;
        
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] - list[groupIndex].back() > limit) {
                list.push_back(deque<int>());
                groupIndex++;
            }
            list[groupIndex].push_back(temp[i]);
            map[temp[i]] = groupIndex;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            int gi = map[nums[i]];
            nums[i] = list[gi].front();
            list[gi].pop_front();
        }
        return nums;
    }
};

int main() {
    vector<int> nums = {4, 2, 6, 1, 3};
    int limit = 2;
    Solution sol;
    vector<int> result = sol.lexicographicallySmallestArray(nums, limit);
    
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
