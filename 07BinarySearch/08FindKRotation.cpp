// Find the index of the minimum element in a rotated sorted array (number of rotations).
#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr) { //index of min element is our answer
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;
    int loc = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[low] <= arr[high]) {
            if(arr[low]<ans){
                loc=low;
                ans=arr[low];
            }
            low=mid+1;
            break;
        }
        if (arr[low] <= arr[mid]) {
            if(arr[low]<ans){
                loc=low;
                ans=arr[low];
            }
            low = mid + 1;
        } else {
            if(arr[mid]<ans){
                loc=mid;
                ans=arr[mid];
            }
            high = mid - 1;
        }
    }
    return loc;
}

int main() {
    vector<int> arr = {15, 18, 2, 3, 6, 12};  // Example rotated sorted array
    int rotationIndex = findKRotation(arr);
    cout << "Rotation count is: " << rotationIndex << endl;
    return 0;
}
