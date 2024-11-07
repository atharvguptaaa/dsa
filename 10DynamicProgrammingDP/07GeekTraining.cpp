#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /* vector<vector<int>> dp;
    int f(int days, int last, vector<vector<int>>& arr) {
        if (days == 0) {
            int maxi = 0;
            for (int task = 0; task <= 2; i++) {
                if (task != last) {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return dp[0][last]=maxi;
        }
        if(dp[days][last]!=-1) return dp[days][last];
        int maxi = 0;
        for (int task = 0; task <= 2; task++) {
            if (task != last) {
                int merit = f(days - 1, task, arr) + arr[days][task];
                maxi = max(maxi, merit);
            }
        }
        return dp[days][last]=maxi;
    }
    
    int maximumPoints(vector<vector<int>>& arr, int n) {
        dp.assign(n,vector<int>(4,-1));
        return f(n - 1, 3, arr);
    } */

//tabulation
/* int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n,vector<int>(4));
        
        dp[0][0]=max(arr[0][1],arr[0][2]); //if task 0 is not chosen
        dp[0][1]=max(arr[0][0],arr[0][2]); //if task 1 is not chosen
        dp[0][2]=max(arr[0][1],arr[0][0]);
        dp[0][3]=max(arr[0][0],max(arr[0][1],arr[0][2])); //if any task is chosen
        
        
        for(int days=1;days<n;days++){
            for(int last=0;last<4;last++){
                
            dp[days][last]=0;
                for(int task=0;task<3;task++){
                if(task!=last){
                    int merit=dp[days-1][task]+arr[days][task];
                    dp[days][last]=max(merit,dp[days][last]);
                }
        }
                
            }
        }    
        return dp[n-1][3];
    } */


   //space optimization
   int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<int> prev(4);
        
        prev[0]=max(arr[0][1],arr[0][2]);
        prev[1]=max(arr[0][0],arr[0][2]);
        prev[2]=max(arr[0][1],arr[0][0]);
        prev[3]=max(arr[0][0],max(arr[0][1],arr[0][2]));
        
        
        for(int days=1;days<n;days++){
            vector<int> temp(4,0);
            for(int last=0;last<4;last++){
                
            
                for(int task=0;task<3;task++){
                    if(task!=last){
                        int merit=prev[task]+arr[days][task];
                        temp[last]=max(merit,temp[last]);
                    }
                }
            }
            prev=temp;
        }
        return prev[3];
    }

};

int main() {
    vector<vector<int>> arr = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n = arr.size();
    Solution obj;
    cout << "Maximum Points: " << obj.maximumPoints(arr, n) << endl;
    return 0;
}
