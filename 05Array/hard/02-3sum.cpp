#include<bits/stdc++.h>
using namespace std;
  // brute 
 /*  using three loops */

  //better approach- hashSet
/*   vector<vector<int>> threeSum(vector<int> &nums) {
    int n=nums.size();
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(nums[i] + nums[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
 */

 // optimal 2 pointer  
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
