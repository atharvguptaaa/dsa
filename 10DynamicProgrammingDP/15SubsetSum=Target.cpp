#include<bits/stdc++.h>
using namespace std;

// Checks if a subset of the given array sums to the target value

//memoization
  /* vector<vector<int>>dp;
    bool f(int i, vector<int>& arr, int target){
        //base-case
        if(target==0) return true;
        if(i==0) return(arr[i]==target);

        if(dp[i][target]!=-1) return (bool)dp[i][target];


        bool notTake=f(i-1,arr,target);
        bool take=false;
        if(arr[i]<=target){
        take=f(i-1,arr,target-arr[i]);
        }

        return dp[i][target]=take or notTake;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        dp.assign(n,vector<int>(target+1,-1));
        return f(n-1,arr,target);
    } 

    //tc- O(n x target) sc-O(n x target) + O(n)
    */

//Tabulation
      /* bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<bool>>dp(n,vector<bool>(target+1));

        //basecase
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }

        if (arr[0] <= target) {
        dp[0][arr[0]]=true;  //cos the first element alone is also a subset( of its own sum)
        }
        
        
        for(int ind=1;ind<n;ind++){
            for(int tgt=1;tgt<=target;tgt++){  //as target >=1

                bool notTake=dp[ind-1][tgt]; //
                bool take=false;
                if(arr[ind]<=tgt){
                take=dp[ind-1][tgt-arr[ind]]; //if pichla wala can do current target minus current element, it means this one can surely do the rest which is itself
                }

                dp[ind][tgt]=take||notTake ;
            }
        }
        return (dp[n-1][target]);
    } 
// dp[x][y] = true means that its possible to achieve the sum 'y' using elements from the subset {arr[0], arr[1], ..., arr[x]}, 
// where 'x' is the index of the last element considered in the subset
*/

//space optimization
bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<bool>prev(target+1);

        //basecase
        prev[0]=true;
        if (arr[0] <= target) {
        prev[arr[0]]=true;  //cos the first element alone is also a subset( of its own sum)
        }
    
        for(int ind=1;ind<n;ind++){
            vector<bool> cur(target+1);
            cur[0]=0;
            for(int tgt=1;tgt<=target;tgt++){  //as target >=1

                bool notTake=prev[tgt];
                bool take=false;
                if(arr[ind]<=tgt){
                take=prev[tgt-arr[ind]];
                }

                cur[tgt]=take||notTake ;
            }
            prev=cur;
        }
        return prev[target];
    }
//tc: O(Nxtarget)
//sc: O(2*target) prev and cur 



int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 15;
    bool result = isSubsetSum(arr, target);
    cout << "Is subset sum possible: " << result << endl;
    return 0;
}

