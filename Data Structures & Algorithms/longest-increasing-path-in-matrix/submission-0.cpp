#include<bits/stdc++.h>
class Solution {
public:

vector<int>x = {0,-1,0,1};
vector<int>y = {-1,0,1,0};

int dp[101][101];
bool IsSafe(int i, int j, vector<vector<int>>& matrix)
{
     if(i<0 or j<0 or i==matrix.size() or j==matrix[0].size()) return 0;
     return 1;
}

    int solve(vector<vector<int>>& matrix, int i, int j)
    {
        if(i<0 or j<0 or i==matrix.size() or j==matrix[0].size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 0;
        for(int k=0;k<4;k++)
        {
            int r = i+x[k];
            int c = j+y[k];

            if(IsSafe(r,c, matrix) && matrix[r][c]>matrix[i][j])
            {
                ans = max(ans, 1+solve(matrix,r,c));
            }
        }

        return dp[i][j] = ans;


    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int ans = 0;
        memset(dp,-1,sizeof dp);
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans = max(ans, solve(matrix,i,j));
            }
        }

        return ans+1;
        
    }
};
