#include<bits/stdc++.h>
using namespace std;

//Brute - by merge function from merge sort
/*  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int m=n1+n2;
        vector<int> temp;
        int left=0,right=0;
        while(left<n1&&right<n2){
            if(nums1[left]<=nums2[right]){
                temp.push_back(nums1[left]);
                left++;
            }
            else{
                temp.push_back(nums2[right]);
                right++; 
            }
        } 
            while(left<n1){
                temp.push_back(nums1[left]);
                left++;
            }
            while(right<n2){
                 temp.push_back(nums2[right]);
                right++; 
            }

            if(m%2==1){
                return temp[(m/2)];
            }
            else{
                return (double)(temp[m/2]+temp[m/2-1])/2.0;
            }

 }; */

//Optimal - binary search approach
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n2<n1)
        return findMedianSortedArrays(nums2,nums1);
        int leftSide=(n1+n2+1)/2;
        int low=0,high=n1;
    
        while(low<=high){
        int mid1=(low+high)>>1;
        int mid2=leftSide-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;

        if(mid1-1>=0) l1=nums1[mid1-1];
        if(mid2-1>=0) l2=nums2[mid2-1];
        if(mid1<n1) r1=nums1[mid1];
        if(mid2<n2) r2=nums2[mid2];
            if(l1<=r2&&l2<=r1){
                if((n1+n2)%2==1){
                    return max(l1,l2);
                }
                else{
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
                break;
            }
            else if(l1>r2){
                high=mid1-1;
            }
            else{
                low=mid1+1;
            }
        }
       

    return 0;
    }

int main()
{
 vector<int> nums1={1,3,5,7,9};
 vector<int> nums2={2,4,6,8,10};
 cout<<findMedianSortedArrays(nums1,nums2);
 return 0;
}