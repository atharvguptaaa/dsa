/*  Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1. */

#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> dp;
//recursive soln
    /* int f(vector<int>& height, int n) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int energyFromOneStep = f(height, n - 1) + abs(height[n - 1] - height[n]);
        int energyFromTwoSteps = INT_MAX;
        if (n > 1) {
            energyFromTwoSteps = f(height, n - 2) + abs(height[n - 2] - height[n]);
        }

        dp[n] = min(energyFromOneStep, energyFromTwoSteps);
        return dp[n];
    }

    int minimumEnergy(vector<int>& height, int n) {
        dp.assign(n + 1, -1);
        return f(height, n - 1);
    } */


//tabulation
     /* int minimumEnergy(vector<int>& height, int n) {
        dp.assign(n+1,-1);
        dp[0]=0;
   
        int energyFromTwoSteps=INT_MAX;
        for(int i=1;i<n;i++){
            int energyFromOneStep =dp[i-1]+abs(height[i-1]-height[i]);
            if(i>1) energyFromTwoSteps=dp[i-2]+abs(height[i-2]-height[i]);
            dp[i]=min(energyFromOneStep, energyFromTwoSteps);
        }
        
        return dp[n-1];
    } */


   //space optimization
       int minimumEnergy(vector<int>& height, int totalStones) {
        int energyToPrevStone = 0;
        int energyToTwoStonesBack = 0;
        int minEnergyForCurrentStone = 0;
        int twoStepJumpEnergy = INT_MAX;

        for(int currentStone = 1; currentStone < totalStones; currentStone++) {
            int oneStepJumpEnergy = energyToPrevStone + abs(height[currentStone - 1] - height[currentStone]);
            if (currentStone > 1) {
                twoStepJumpEnergy = energyToTwoStonesBack + abs(height[currentStone - 2] - height[currentStone]);
            }
            minEnergyForCurrentStone = min(oneStepJumpEnergy, twoStepJumpEnergy);
            energyToTwoStonesBack = energyToPrevStone;
            energyToPrevStone = minEnergyForCurrentStone;
        }

        return minEnergyForCurrentStone;
   
    }

};

int main() {
    int n = 6;
    vector<int> height = {30, 10, 60, 10, 60, 50};

    Solution sol;
    int result = sol.minimumEnergy(height, n);

    cout << result << endl;

    return 0;
}
