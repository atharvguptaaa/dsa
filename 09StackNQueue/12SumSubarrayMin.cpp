// Program to calculate the sum of minimums of all subarrays of an array.

#include <bits/stdc++.h>
using namespace std;

// Brute force
/* int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int mod = 1e9 + 7; //given
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int mini = arr[i];
        for(int j = i; j < n; j++) { //i to j is our subarray
            mini = min(mini, arr[j]);
            sum = (sum + mini) % mod;
        }
    }
    return sum;
}
//tc-O(N^2)*/

// Optimal Approach
vector<int> calcNse(vector<int> &arr, int n)
{
    vector<int> nse(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> calcPsee(vector<int> &arr, int n)
{
    vector<int> psee(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    int mod = (int)1e9 + 7;
    int sum = 0;
    vector<int> nse = calcNse(arr, n);
    vector<int> psee = calcPsee(arr, n);
    for (int i = 0; i < n; i++)
    {
        int left = i - psee[i];
        int right = nse[i] - i;
        sum = (sum + (left * right * 1ll * arr[i]) % mod) % mod;
    }
    return sum;
}

//tc and sc: O(5N)

int main()
{
    vector<int> arr = {3, 1, 2, 4}; // hardcoded values
    cout << sumSubarrayMins(arr) << endl;
    return 0;
}
