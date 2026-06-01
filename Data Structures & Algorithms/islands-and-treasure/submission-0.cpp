class Solution {
public:

    vector<int>x = {0,-1,0,1};
    vector<int>y = {-1, 0, 1, 0};
    int land;

    bool isSafe(int r, int c, int n, int m, vector<vector<int>>& grid)
{
    if (r < 0)
    {
        //cout << "Rejected: r < 0, r = " << r << endl;
        return false;
    }

    if (c < 0)
    {
        //cout << "Rejected: c < 0, c = " << c << endl;
        return false;
    }

    if (r >= n)
    {
        //cout << "Rejected: r >= n, r = " << r << ", n = " << n << endl;
        return false;
    }

    if (c >= m)
    {
        //cout << "Rejected: c >= m, c = " << c << ", m = " << m << endl;
        return false;
    }

    if (grid[r][c] != 2147483647)
    {
        //cout << "Rejected: grid[" << r << "][" << c << "] = "
             //<< grid[r][c] << " (expected 2147483647)" << endl;
        return false;
    }

    //cout << "Accepted: (" << r << ", " << c << ")" << endl;
    return true;
}
    void islandsAndTreasure(vector<vector<int>>& grid) {

        auto treasure = 0;
        auto water = -1;
        land = 2147483647;


        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans = grid;
        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==treasure)
                {
                    //cout<<"push "<<i<<" "<<j<<endl;
                q.push({i,j});
                }
              
            }
        }
        int move = 1;
        while(!q.empty())
        {
           int size = q.size();

           while(size--)
           {
             auto it = q.front(); q.pop();

                int r = it.first;
                int c = it.second;

                for(int i = 0;i<4;i++)
                {
                    int nr = r+x[i];
                    int nc = c+y[i];

                    if(isSafe(nr,nc,n,m, grid))
                    {
                        //cout<<"updating "<<nr<<" "<<nc<<" to "<<move<<endl;
                        grid[nr][nc] = move;
                        q.push({nr,nc});
                    }
                    else
                    {
                        //cout<<"rejected "<<nr<<" "<<nc<<endl;
                    }
                } 
           }
           move++;
        }

        
        
    }
};
