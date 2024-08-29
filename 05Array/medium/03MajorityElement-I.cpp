//Find the Majority Element that occurs more than N/2 times 
#include <bits/stdc++.h>
using namespace std;

//brute -loop inside loop

//better- hashmap 
/* int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    map<int, int> mpp;

    //O(NlogN)
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }
    
    //O(N)
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }
    return -1;
} */

//Optimal- Moore's voting algo
int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    int el = nums[0];
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            el = nums[i];
            cnt = 1;
        }
        else if(el == nums[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    if (cnt <= 0)
        return -1;
    else
    {
        int elCnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == el)
                elCnt++;
        }
        if (elCnt > (n / 2))
            return el;
        else
            return -1;
    }
}

int main()
{
    //assume arr always have a majority element
    vector<int> nums={1,2,1,2,1,2,1,2,1,1};
    cout<<majorityElement(nums);
    return 0;
}