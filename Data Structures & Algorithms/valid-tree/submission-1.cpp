class Solution {
public:
    vector<int>adj[101];

    bool dfs(int n, int node, int par, vector<bool>&vis)
    {
        if(vis[node]) return true; // cycle

        vis[node] = 1;

        for(auto & x : adj[node])
        {
            if(x==par) continue;

            if(vis[x]) return true; // cycle.

            if(dfs(n, x, node, vis)) return true;
        }

        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);

        for(auto & x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        if(dfs(n,0,-1,vis)) return false;

        for(int i=0;i<n;i++)
        {
            if(!vis[i]) return false;
        }
        return true;
    }
};
