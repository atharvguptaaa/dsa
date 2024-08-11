#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &nums){
int n=nums.size();
int ind=-1;
for(int i=n-2;i>=0;i--){               //find breakpoint
    if(nums[i]<nums[i+1]){
        ind=i;
        break;
    }
}
if(ind==-1){
    reverse(nums.begin(),nums.end());       //if no breakpoint, reverse whole array
    return nums;
}

for(int i=n-1;i>=ind+1;i--){           //if found, swap it with smallest no. to the right, bigger than itself
    if(nums[i]>nums[ind]){             
    swap(nums[i],nums[ind]);
    break;
    }
}
reverse(nums.begin()+ind+1,nums.end());   //reverse the array to the right of ind to sort it
return nums;
}


int main()
{
 vector<int> nums={2,1,5,4,3,0,0};
 nums=nextPermutation(nums);
 for(auto it:nums ){
    cout<<it<<" ";
 }
 return 0;
}