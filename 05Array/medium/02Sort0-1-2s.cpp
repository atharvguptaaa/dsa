#include<bits/stdc++.h>
using namespace std;

//brute -use sorting of any kind

//better -counting
/* void sortArray(vector<int>& nums) {
    int cnt0=0,cnt1=0,cnt2=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0)cnt0++;
        if(nums[i]==1)cnt1++;
        if(nums[i]==2)cnt2++;
    }
    for(int i=0;i<cnt0;i++){
        nums[i]=0;
    }
      for(int i=cnt0;i<cnt1+cnt0;i++){
        nums[i]=1;
    }
      for(int i=cnt1+cnt0;i<cnt0+cnt1+cnt2;i++){
        nums[i]=2;
    }
} */


//optimal- dutch national flag algo
void sortArray(vector<int>& nums) {
    int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }


int main()
{
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr);
    cout << "After sorting:" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0; 
}