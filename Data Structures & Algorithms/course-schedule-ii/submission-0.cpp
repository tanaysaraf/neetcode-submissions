class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
       
        vector<int>in(n,0);
        map<int,vector<int>>adj;
        for(auto & x : prerequisites)
        {
            in[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            auto it = q.front(); q.pop();
            ans.push_back(it);

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
        if(ans.size()<n) return {};
        return ans; 
    }
};
