#include<bits/stdc++.h>
using namespace std;
   int giveUnique(vector<int> &nums)
   {
    int i=0;
    for(int j=1;j<nums.size();j++){
                if(nums[j]!=nums[i]){
                    nums[i+1]=nums[j];
                    i++;
                }
            }
            
    return i+1;
   }

   
int main()
{
    vector<int> nums={1,1,2,2,2,3,3,3,3,4};
    cout<< giveUnique(nums);
   
}
