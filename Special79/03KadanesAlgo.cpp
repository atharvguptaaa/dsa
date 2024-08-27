
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        long long maxSum=LONG_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(sum,maxSum);
            if(sum<0){
                sum=0;    
            }
        }
        return maxSum;
    }

int main()
{
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    long long maxSum = maxSubarraySum(arr);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}