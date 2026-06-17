#include<string.h>
class Solution {
public:
    #define ll long long
    ll dp[301][301];
    ll solve(vector<int>&nums ,int i, int j)
    {
        // base 
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        ll ans = 0;
        for(int k=i;k<=j;k++)
        {
            // burst kth ballon
            ll temp = 1ll*nums[i-1]*nums[k]*nums[j+1] + solve(nums,i,k-1) + solve(nums,k+1,j);
            ans = max(ans, temp);
        }
        return dp[i][j]= ans;


    }
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        memset(dp,-1,sizeof dp);

        return solve(nums,1,nums.size()-2);
        
    }
};
