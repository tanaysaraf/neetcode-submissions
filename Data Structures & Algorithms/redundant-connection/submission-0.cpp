class Solution {
public:
    int rank[101];
    int parent[101];

    int findParent(int node)
    {
        if(parent[node]==node) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool join(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);

        //cout<<u<<" "<<v<<endl;

        if(u==v) return false;

        if(rank[u]>=rank[v])
        {
            rank[u]+=rank[v];
            parent[v]=u;
        }
        else
        {
            rank[v]+=rank[u];
            parent[u]=v;
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        vector<int>ans;

        for(int i=0;i<101;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }

        for(auto & x : edges)
        {
            int u = x[0];
            int v = x[1];

            if(!join(u,v))
            {
                return {u,v};
            }
        }

        return ans;
    }
};
