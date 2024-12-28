#include<bits/stdc++.h>
using namespace std;

//Can given array be partitioned into subsets with equal sums

 /*  vector<vector<int>>dp;
    bool f(int i, vector<int>& nums, int target){
        //base-case
        if(target==0) return true;
        if(i==0) return(nums[i]==target);

        if(dp[i][target]!=-1) return (bool)dp[i][target];


        bool notTake=f(i-1,nums,target);
        bool take=false;
        if(nums[i]<=target){
        take=f(i-1,nums,target-nums[i]);
        }

        return dp[i][target]=take or notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if (sum%2!=0) return false;
        int target=sum/2;
        dp.assign(n,vector<int>(target+1,-1));
        return f(n-1,nums,target);

    } */

   //space opt tabulation

   bool canPartition(vector<int>& nums) {
         int n=nums.size();
         int sum=0;
         for(auto it:nums) sum+=it;
         if(sum%2!=0) return false;
         int target=sum/2;
        vector<bool>prev(target+1);

        //basecase
        prev[0]=true;
        if (nums[0] <= target) {
        prev[nums[0]]=true; 
        }
    
        for(int ind=1;ind<n;ind++){
            vector<bool> cur(target+1);
            cur[0]=0; //basecase
            for(int tgt=1;tgt<=target;tgt++){  //as target >=1

                bool notTake=prev[tgt];
                bool take=false;
                if(nums[ind]<=tgt){
                take=prev[tgt-nums[ind]];
                }

                cur[tgt]=take||notTake ;
            }
            prev=cur;
        }
        return prev[target];

    }

    int main() {
    vector<int> nums = {2,3,3,3,4,5};
    bool result = canPartition(nums);
    if(result)
    cout << "Is subset sum possible: " << "true" << endl;
    else
    cout << "Is subset sum possible: " << "false" << endl;

    
    return 0;
}
