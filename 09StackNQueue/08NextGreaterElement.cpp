#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge(nums2.size(), -1);
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            int index = distance(nums2.begin(), it);
            ans[i] = nge[index];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout << "Next greater elements for nums1: ";
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}

//tc O(N)+ O(N) -outer loop & while loop wc
//sc O(N)+ O(N) - ans and stack