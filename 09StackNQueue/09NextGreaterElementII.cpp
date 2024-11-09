// Finds the next greater element for each element in a circular array
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    stack<int> st;
    vector<int> nge(n, -1);

    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }
        if (i < n) { //when you actually start adding in nge after half the hypothetical double array is traversed
            nge[i] = st.empty() ? -1 : st.top();
        }
        st.push(nums[i % n]);
    }
    return nge;
}

int main() {
    vector<int> nums = {1, 2, 1}; // Example input
    vector<int> result = nextGreaterElements(nums);
    for (int val : result) {
        cout << val << " ";
    }
    return 0;
}

//tc O(2N)+ O(2N) -outer loop & while loop wc
//sc O(2N)+ O(N) - stack and nge