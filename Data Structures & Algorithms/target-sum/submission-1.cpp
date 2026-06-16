#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[21][2001];

    int solve(int amt, int i, vector<int>& nums) {
        if (amt < -1000 || amt > 1000) return 0;

        if (i == nums.size()) {
            return amt == 0;
        }

        if (dp[i][amt + 1000] != -1) {
            return dp[i][amt + 1000];
        }

        int ans = solve(amt - nums[i], i + 1, nums)
                + solve(amt + nums[i], i + 1, nums);

        return dp[i][amt + 1000] = ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return solve(target, 0, nums);
    }
};