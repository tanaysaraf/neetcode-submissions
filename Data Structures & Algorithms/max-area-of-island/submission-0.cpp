class Solution {
public:
   void solve(vector<vector<int>>& grid, int i, int j, int &cnt)
    {
        if(i<0 or j<0 or i==grid.size() or j==grid[0].size() or grid[i][j]==0)
        return;

        cnt++;

        //cout<<i<<" "<<j<<endl;
        grid[i][j]=0;
        solve(grid, i+1,j, cnt);
        solve(grid, i-1,j, cnt);
        solve(grid, i,j+1, cnt);
        solve(grid, i,j-1, cnt);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int ans=0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    //cout<<i<<" "<<j<<endl;
                    //cout<<"----------------\n";
                    int cnt=0;
                    solve(grid,i,j, cnt);
                    ans = max(ans, cnt);
                }
            }
        }

        return ans;
    }
};
