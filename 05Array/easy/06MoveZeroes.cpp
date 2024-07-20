#include<bits/stdc++.h>
using namespace std;

void moveZeros(int n, vector<int>&nums) {
int j = -1;
for(int i=0;i<n;i++) {
if(nums[i] == 0) {
j = i;
break;
}
}
// no non zero numbers
if(j == -1) return;
for(int i = j+1;i<n;i++) {
if(nums[i] != 0) {
swap(nums[i],nums[j]);
j++;
}
} 
}

int main(){
    vector<int> nums = {1,0,0,1};
    int n=nums.size();
    moveZeros(n,nums);   
    cout<<"After moving zeroes"<<endl;
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}


// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int a,b;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==0){
//                 a=i;
//                 b=i+1;
//                 break;
//             }
  
//         }
//                    if(a==nums.size()-2 && nums[b]!=0){
//              swap(nums[a],nums[b]);
//         }
        
      
//             for(b;b<nums.size();b++){
//                 if(nums[b]!=0){
//                     swap(nums[a],nums[b]);
//                     a++;
//                 }


//             }
             
// }
// };