class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>>dis(n,vector<int>(n,1e9));
        vector<int>x = {0,-1,0,1};
        vector<int>y = {-1,0,1,0};

        dis[0][0]=grid[0][0];

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0}); // dis , r, c

        while(!pq.empty())
        {
            auto it = pq.top(); pq.pop();

            for(int i=0;i<4;i++)
            {
                int r = it[1]+x[i];
                int c = it[2]+y[i];

                if(r>=0 and c>=0 and r<n and c<n and dis[r][c]>max(grid[r][c], it[0]))
                {
                    dis[r][c] = max(grid[r][c], it[0]);
                    pq.push({dis[r][c],r,c});
                }
            }
        }

        return dis[n-1][n-1];
    }
};
