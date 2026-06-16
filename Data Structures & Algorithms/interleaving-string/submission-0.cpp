#include<string.h>
class Solution {
public:
int dp[101][101];
bool solve(string s1, string s2, string s3, int i, int j, int k)
{
    if(k==s3.size()) return s1.size()==i && s2.size()==j;
    
    if(dp[i][j]!=-1) return dp[i][j];

    bool ans = false;
    if(i<s1.size() && s1[i]==s3[k]) ans|=solve(s1,s2,s3,i+1,j,k+1);
    if(ans) return dp[i][j]= ans;

    if(j<s2.size() && s2[j]==s3[k]) ans|=solve(s1,s2,s3,i,j+1,k+1);

    return dp[i][j] =  ans;
}
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof dp);
        return solve(s1,s2,s3,0,0,0);
    }
};
