/* There are n students in a class numbered from 0 to n - 1. The teacher will give each student a problem starting with the student number 0, then the student number 1, and so on until the teacher reaches the student number n - 1. After that, the teacher will restart the process, starting with the student number 0 again.

You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.

Return the index of the student that will replace the chalk pieces. */

#include<bits/stdc++.h>
using namespace std;

//better
/*  int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i = 0; i < chalk.size(); i++){
            sum += chalk[i];
        }
        k = k % sum;
        int i = 0;
        while(k >= chalk[i]){
            k -= chalk[i];
            i++;
        }
        return i;
    } */

//optimal
 int bS(vector<long long>& prefix, int k){
        int low=0;
        int high=prefix.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(prefix[mid]==k){
                return mid+1;
            }
            else if(prefix[mid]<k){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
    int chalkReplacer(vector<int>& chalk, int k) {
        long long prefixSum=0;
        vector<long long> prefix(chalk.size());
        for(int i=0;i<chalk.size();i++){
            prefixSum+=chalk[i];
            prefix[i]=prefixSum;
        }
        k=k%prefix.back();
        return bS(prefix,k);
     
    }   //TC: O(n)+O(logn) and SC:O(n)

int main()
{
 vector<int> chalk={3,4,1,2};
 int k=25;
 cout<<chalkReplacer(chalk,k);
 return 0;
}