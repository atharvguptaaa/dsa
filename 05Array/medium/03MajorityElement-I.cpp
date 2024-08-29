#include <bits/stdc++.h>
using namespace std;

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
    vector<int> nums={1,2,1,2,1,2,1,2,1,1};
    cout<<majorityElement(nums);
    return 0;
}