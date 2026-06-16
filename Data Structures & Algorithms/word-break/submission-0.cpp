#include<string.h>
class Solution {
public:
    int dp[201];
    bool solve(string s, set<string>&dict, int i)
    {
        if(i==s.size()) return true;

        if(dp[i]!=-1) return dp[i];

        bool ans = false;

        for(int j=i;j<s.size();j++)
        {
            string left = s.substr(i,j-i+1);

            if(dict.find(left)!=dict.end())
            ans|=solve(s,dict,j+1);

            if(ans) return ans;
        }

        return dp[i] = ans;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>dict(wordDict.begin(), wordDict.end());
        memset(dp,-1,sizeof dp);

        return solve(s,dict,0);

    }
};
