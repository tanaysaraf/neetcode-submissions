class Solution {
public:
vector<int>x = {0,-1,0,1};
vector<int>y = {-1,0,1,0};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        // find all blocks where pacific water comes.
        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>ans2(n,vector<int>(m,0));
        vector<vector<int>>ret;
        for(int j=0;j<m;j++)
        {
            q.push({0,j});
            ans[0][j]++;
        }

        for(int i=1;i<n;i++)
        {
            q.push({i,0});
            ans[i][0]++;
        }

        

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            // explore
            for(int i=0;i<4;i++)
            {
                int r = it.first+x[i];
                int c = it.second+y[i];

                if(r>=0 and c>=0 and r<n and c<m and heights[r][c]>=heights[it.first][it.second] && ans[r][c]==0)
                {
                    q.push({r,c});
                    ans[r][c]++;
                }
            }

        }


        for(int j=0;j<m;j++)
        {
            q.push({n-1,j});
            ans2[n-1][j]++;
        }

        for(int i=n-2;i>=0;i--)
        {
            q.push({i,m-1});
            ans2[i][m-1]++;
        }

        

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            // explore
            for(int i=0;i<4;i++)
            {
                int r = it.first+x[i];
                int c = it.second+y[i];

                if(r>=0 and c>=0 and r<n and c<m and heights[r][c]>=heights[it.first][it.second] && ans2[r][c]==0)
                {
                    q.push({r,c});
                    ans2[r][c]++;
                }
            }

        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ans[i][j]+ans2[i][j]==2)
                {
                    ret.push_back({i,j});
                }
            }
        }

        //  for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<"-------------"<<endl;
        //       for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<ans2[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }



        return ret;


        
    }
};
