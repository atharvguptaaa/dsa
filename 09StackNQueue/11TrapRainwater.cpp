// Program to calculate the total water trapped after raining given heights of bars.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Approach-1 
/* int trap(vector<int>& height) {
    int n = height.size();
    vector<int> sufmax(n);
    sufmax[n-1] = height[n-1];
    for(int i = n - 2; i >= 0; i--) {
        sufmax[i] = max(sufmax[i + 1], height[i]);
    }
    int total = 0;
    int prefmax = height[0];
    for(int i = 1; i < n; i++) {
        prefmax = max(prefmax, height[i]);
        if(height[i] < prefmax && height[i] < sufmax[i]) {
            total += min(prefmax, sufmax[i]) - height[i];
        }
    }
    return total;
} 

//tc-O(N)+O(N)
//sc-O(N)*/

//space optimized approach
 int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1,lmax=0,rmax=0,total=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(lmax>height[l]){
                    total+=lmax-height[l];
                }
                else{
                    lmax=height[l];
                    }
                    l++;
            }
            else{
                if(rmax>height[r]){
                    total+=rmax-height[r];
                }
                else{
                    rmax=height[r];
                    }
                    r--;
            }
        }
        return total;
    }
    //tc: O(N)
    //sc: O(1)

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // hardcoded heights
    cout << trap(height) << endl;
    return 0;
}
