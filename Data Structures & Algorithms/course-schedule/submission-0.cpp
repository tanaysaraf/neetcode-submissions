class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {


        vector<int>in(n,0);
        map<int,vector<int>>adj;
        for(auto & x : prerequisites)
        {
            in[x[1]]++;
            adj[x[0]].push_back(x[1]);
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            q.push(i);
        }
        int cnt=0;
        while(!q.empty())
        {
            auto it = q.front(); q.pop();
            cnt++;

            // relax all neighbours
            for(auto & x : adj[it])
            {
                in[x]--;
                if(in[x]==0)
                {
                    q.push(x);
                }
            }
        }

        return cnt==n;
        
    }
};
