#include<bits/stdc++.h>
using namespace std;
    
  vector<vector<int>> threeSum(vector<int>& nums) {
         int n=nums.size();
         vector<vector<int>> ans;
         sort(nums.begin(),nums.end());
         for(int i=0;i<n;i++){
         if(i>0&&nums[i]==nums[i-1])continue;   //handle duplicate i's
         int j=i+1;
         int k=n-1;
         
         while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0) j++;
            else if(sum>0) k--;
            else{
                ans.push_back({nums[i],nums[j],nums[k]});
                //handle duplicates
                while(j<k&& nums[j]==nums[j+1])j++;
                while(j<k&& nums[k]==nums[k-1])k--;
                //increment values after pushing
                j++;
                k--;
            }
         }
         
         }
        return ans;
    
    }

    int main(){
 vector<int> nums={2,1,5,4,3,0,0,-1,0,-2};
 vector<vector<int>> ans=threeSum(nums);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
 return 0;
}
