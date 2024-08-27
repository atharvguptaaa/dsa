#include <bits/stdc++.h>
using namespace std;

//Brute Force
/* vector<int> twoSum(int n, vector<int> arr, int target){
    vector<int> ans;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i+1; j < n; j++)
        {
            if(arr[i]+arr[j]==target){
                ans.push_back(i);
                ans.push_back(j);
            }
        }
        
    }
    return ans;
} */

//Optimal
vector<int> twoSum(int n, vector<int> arr, int target){
    vector<int> ans;
    map<int,int> mpp;
    for (size_t i = 0; i < n; i++)
    {
       int rem=target-arr[i];
       if(mpp.find(rem)!=mpp.end()){
        ans.push_back(i);
        ans.push_back(mpp[rem]);
        return ans;
       }
       mpp[arr[i]]=i;        
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer is: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}