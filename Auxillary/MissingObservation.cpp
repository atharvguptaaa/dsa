/* 2028. Find Missing Observations : You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.

You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.

Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.

The average value of a set of k numbers is the sum of the numbers divided by k.

Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m. */
#include<bits/stdc++.h>
using namespace std;


    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        long long sumM;
        for(int i=0;i<m;i++){
            sumM+=rolls[i];
        }
        long long sumN=mean*(m+n)-sumM;
        
        long long minSumN=n*1;
        long long maxSumN=n*6;
        if(sumN<minSumN||sumN>maxSumN) return {};
        // Create a result array initialized with 1 (the minimum value)
        vector<int> result(n,1);
        sumN-=n;// We have already assigned '1' to each element
        for(int i=0;i<n && sumN>0;i++){
            int add = min(5, (int)sumN); // We can add at most 5 to each element to keep it <= 6
            result[i]+=add;
            sumN-=add;
        }

        return result;
    }


int main()
{
 vector<int> rolls={3,2,4,3};
 int mean=4,n=2;
 vector<int> ans=missingRolls(rolls,mean,n);
 for (int i = 0; i < n; i++)
 {
    cout<<ans[i]<<" ";
 }
 
 return 0;
}