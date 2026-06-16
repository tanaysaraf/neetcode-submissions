#include<string.h>
class Solution {
public:
int dp[101][5001];
    int solve(int amt, int i, vector<int>&coins)
    {
        if(amt==0) return 1;
        if(amt<0 or i==coins.size()) return 0;

        if(dp[i][amt]!=-1) return dp[i][amt];

        int ans = solve(amt-coins[i], i, coins);
        ans+=solve(amt, i+1, coins);
        return dp[i][amt] = ans;
    }
    int change(int amount, vector<int>& coins) {

        memset(dp,-1,sizeof dp);
        return solve(amount, 0, coins);
        
    }
};
