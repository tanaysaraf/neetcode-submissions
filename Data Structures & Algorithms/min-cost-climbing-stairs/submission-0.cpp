#include <string.h>
class Solution {
public:

    int dp[101];

    int solve(vector<int>&cost, int i, int n)
    {
        if(i==n) return 0;
        if(i>n) return 1e9;

        if(dp[i]!=-1) return dp[i];

        return dp[i] = cost[i]+min(solve(cost,i+1,n), solve(cost,i+2,n));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp,-1,sizeof dp);
        return min(solve(cost,0,n) , solve(cost, 1,n));
    }
};
