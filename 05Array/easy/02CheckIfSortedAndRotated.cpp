#include<bits/stdc++.h>
using namespace std;
   bool check(vector<int> &nums) {
        int n=nums.size();
        int count=0;
     for(int i=0;i<n;i++){
        if(nums[i]>nums[(i+1)%n]){
            count++;
        }
     }  
     if(count>1)
     return false;
     else 
     return true;
    }
int main()
{
    vector<int> nums={2,3,4,5,6,1,2};
    cout<< check(nums);
}