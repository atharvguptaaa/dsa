#include <bits/stdc++.h>
using namespace std;

// Iterative BS
/* int binarySearch(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int ans = binarySearch(arr, 11);
    cout << ans;
}
 */

// Recursive BS
int binarySearch(vector<int> &arr, int target, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (target == arr[mid])
        return mid;
    else if (target > arr[mid])
        return binarySearch(arr, target, mid + 1, high);
    return binarySearch(arr, target, low, mid - 1);
}
int main()
{
    vector<int> arr = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    int n = arr.size();
    int ans = binarySearch(arr, 6, 0, n - 1);
    cout << ans;
}