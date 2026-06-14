#include<string.h>
class Solution {
public:
    int dp[101];
    int solve(string s, int i)
    {
        if(i>=s.size()) return 1;

        if(dp[i]!=-1) return dp[i];

        int ans = 0;
        // take 1 letter
        if(s[i]!='0')
        {
            ans+=solve(s,i+1);
        }

        // take 2
        if(s[i]!='0' && i+1<s.size() && stoi(s.substr(i,2))<=26)
        {
            ans+=solve(s,i+2);
        }

        return dp[i] = ans;

    }
    int numDecodings(string s) {
        
        memset(dp,-1,sizeof dp);

        return solve(s,0);
    }
};
