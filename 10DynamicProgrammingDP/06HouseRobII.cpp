//All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 

#include<bits/stdc++.h>
using namespace std;

int robbing(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        int prev=nums[0];
        int prev2=0;
        int curi=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i]+prev2;
            int noPick=prev;
            curi=max(pick,noPick);

            prev2=prev;
            prev=curi;
        }
        return curi;
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }

        return max(robbing(temp1),robbing(temp2));
    }

int main()
{
 vector<int> nums = {200, 300, 200};
 cout << rob(nums) << endl;  
 return 0;
}