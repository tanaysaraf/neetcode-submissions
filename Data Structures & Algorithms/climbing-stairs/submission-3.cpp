#include <string.h>
class Solution {
public:
    int dp[50];
    int solve(int n)
    {
        if(n==0) return 1;
        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];

        return dp[n] = solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {

        //memset(dp,-1,sizeof(dp));

        dp[0]=1;
        dp[1]=1;
        int m1=1;
        int m2=1;
        int cutt=1;
        for(int i=2;i<=n;i++)
        {
            cutt = m1+m2;
            m2 = m1;
            m1 = cutt;
        }

        return cutt;
    }
};
