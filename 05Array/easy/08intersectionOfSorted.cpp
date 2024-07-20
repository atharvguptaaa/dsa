#include <bits/stdc++.h>
using namespace std;

/**
 * Finds the intersection of two integer vectors.
 * 
 * Compares the elements of the two input vectors and returns a new vector containing the common elements.
 * 
 * @param nums1 The first input vector of integers.
 * @param nums2 The second input vector of integers.
 * @return A vector containing the common elements of the two input vectors.
 */
vector<int> findIntersection(vector<int>& nums1, vector<int>& nums2){
    int n=nums1.size();
    int m=nums2.size();
    int i=0,j=0;
    vector<int> in;

    while(i<n&&j<m){
        if(nums1[i]==nums2[j]){
            if(in.size() == 0  || in.back()!=nums1[i]){
                in.push_back(nums1[i]);
            }
            j++;
            i++;  
        }
        else if(nums1[i]>nums2[j]){
            j++;  
        }
        else{
            i++;
        }
    }
    return in;
}



int main()
{
    vector<int> nums1 = {1,2,4,5};
    vector<int> nums2 = {2,2,3,4,5};
    vector<int> ans = findIntersection(nums1, nums2);
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

