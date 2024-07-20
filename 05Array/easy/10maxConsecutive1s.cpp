// cpp code for max consecutive 1s in a vector array
#include <bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(vector<int> &nums)
{
    int maxCount = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            count++;
            maxCount = max(maxCount, count);
        }
        else
        {
            count = 0;
        }
    }
    return maxCount;
}

int main()
{
   
    vector<int> nums={1,1,0,0,0,1,0,1,1,1,1,0,1,0,1,1,1,1,1,1,0,0,1,1,1,1};
    cout << maxConsecutiveOnes(nums) << endl;
    return 0;
}
