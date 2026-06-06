class Solution {
public:

    int parent[1001];
    int size[1001];

    int GetParent(int node)
    {
        if(parent[node]==node) return node;
        return parent[node] = GetParent(parent[node]);
    }

    bool join(int u, int v)
    {
        u = GetParent(u);
        v = GetParent(v);

        if(u==v) return false;

        if(size[u]>=size[v])
        {
            size[u]+=size[v];
            parent[v] = u;
        }
        else
        {
            size[v]+=size[u];
            parent[u] = v;
        }

        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        vector<vector<int>>edges;
        int n = points.size();

        for(int i = 0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]- points[j][1]);

                edges.push_back({dist,i,j});
            }
        }

        sort(begin(edges),end(edges));
        int ans = 0;

        for(int i=0;i<edges.size();i++)
        {
            //cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<edges[i][2]<<endl;
            if(join(edges[i][1], edges[i][2]))
            ans+=edges[i][0];
        }

        return ans;
    }
};
