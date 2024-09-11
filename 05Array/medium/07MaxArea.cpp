// 11. Container With Most Water
/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store. 

e.g. Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49 , as index 1 and 9 form the max container*/
#include<bits/stdc++.h>
using namespace std;

//brute force
/* int maxArea(vector<int>& height) {
        int maxAr=-1;
        for(int x=0;x<height.size();x++){

            for(int y=x+1;y<height.size();y++){
                int smaller=min(height[y],height[x]);
                maxAr=max(maxAr,(y-x)*smaller);
            }
        }
        return maxAr;
} */
//Optimal 2 pointer approach
int maxArea(vector<int>& height) {
    int  i=0,j=height.size()-1;
    int maxAr=0;
    while(i<j){
        if(height[i]<height[j]){
            maxAr=max(maxAr,(j-i)*height[i]);
            i++;
        }
        else{
            maxAr=max(maxAr,(j-i)*height[j]);
            j--;
        }
    }
    return maxAr;
}

int main()
{
 vector<int> height={1,8,6,2,5,4,8,3,7};
 cout<<"Max Area is : "<<maxArea(height);
 return 0;
}