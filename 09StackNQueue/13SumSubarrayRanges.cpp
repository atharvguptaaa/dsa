// Calculate the sum of the ranges of all subarrays

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> calcNse(vector<int> &nums, int n)
{
    vector<int> nse(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> calcPsee(vector<int> &nums, int n)
{
    vector<int> psee(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

vector<int> calcNge(vector<int> &nums, int n)
{
    vector<int> nge(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    
    return nge;
}

vector<int> calcPgee(vector<int> &nums, int n)
{
    vector<int> pgee(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }
        pgee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    
    return pgee;
}

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long sum = 0;
    vector<int> nse = calcNse(nums, n);
    vector<int> psee = calcPsee(nums, n);
    vector<int> nge = calcNge(nums, n);
    vector<int> pgee = calcPgee(nums, n);
    for (int i = 0; i < n; i++)
    {
        int lMin = i - psee[i];
        int rMin = nse[i] - i;
        int lMax = i - pgee[i];
        int rMax = nge[i] - i;

        sum = (sum + (lMax * rMax * 1ll * nums[i] - lMin * rMin * 1ll * nums[i]));
    }
    return sum;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    cout << "The sum of subarray ranges is: " << subArrayRanges(nums) << endl;
    return 0;
}
