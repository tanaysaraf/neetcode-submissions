#include<bits/stdc++.h>
class Solution {
public:
int dp[1001][1001];
int solve(string s, string t, int i, int j) {

    if(i==s.size() and j==t.size()) return 0;
    // if(i==s.size() or j==t.size()) return 1e9;

    if(i==s.size()) return t.size()-(j);
    if(j==t.size()) return s.size()-(i);

    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    if(s[i]==t[j])
    {
        ans=solve(s,t,i+1,j+1);
    }
    else
    {
        ans = 1+min(solve(s,t,i+1,j+1), min(solve(s,t,i,j+1), solve(s,t,i+1,j)));
    }


    return dp[i][j]= ans;
    
}
    int minDistance(string word1, string word2) {
        
        memset(dp,-1,sizeof dp);
        return solve(word1,word2,0,0);
    }
};
