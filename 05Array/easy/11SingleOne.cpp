//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
#include<bits/stdc++.h>
using namespace std;

//better approach by map hashing:
/* int singleNumber(vector<int>& nums) {
    map<long long, int> mpp;

    for(long long i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }
    for(auto it: mpp){
        if(it.second==1){
            return it.first;
        }
    }
    
    // Default return if no single number is found
    return -1;
} */



//Optimal approach by XOR
int singleNumber(vector<int>& nums) {
        int xorr=0;
        for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
        }
        return xorr;
    }

int main(){
    vector<int> nums={2,2,1,3,1,3,9,2,8,2,9};
    cout<<singleNumber(nums);

    return 0;
}