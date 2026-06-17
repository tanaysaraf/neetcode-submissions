#include<bits/stdc++.h>
class Solution {
public:

    int dp[21][21];
    bool solve(string s, string p, int i, int j)
    {
        if(j>=p.size()) return i>=s.size();

        if(i<s.size() && dp[i][j]!=-1) return dp[i][j];

        bool firstMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');

        bool ans;

        if (j + 1 < p.size() && p[j + 1] == '*') {

            ans = solve(s, p, i, j + 2) ||        // take 0 occurrences

                  (firstMatch && solve(s, p, i + 1, j)); // take 1+ occurrences

        } else {

            ans = firstMatch && solve(s, p, i + 1, j + 1);

        }
       


         if(i<s.size()) dp[i][j]=ans;
         return ans;

    }
    bool isMatch(string s, string p) {
        
        memset(dp,-1,sizeof dp);

        return solve(s,p,0,0);
        
    }
};
