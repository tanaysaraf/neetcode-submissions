#include<string.h>
class Solution {
public:

    int dp[10001][11];
    int solve(vector<int>&coins, int amt, int i)
    {

       if(amt==0) return 0;
       if(amt<0 or i==coins.size()) return 1e9;

       if(dp[amt][i]!=-1) return dp[amt][i];

       int ans = solve(coins, amt, i+1);
       ans = min(ans, solve(coins, amt-coins[i], i)+1);
       return dp[amt][i] = ans;

    }
    int coinChange(vector<int>& coins, int amount) {
        
        memset(dp,-1,sizeof dp);
        int ans = solve(coins, amount, 0);
        if(ans>=1e9) return -1;
        return ans;
    }
};
