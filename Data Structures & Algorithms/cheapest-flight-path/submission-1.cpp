class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<pair<int,int>>adj[101];

        for(auto & x : flights)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }
        pq.push({0,src,0}); // stops , node, dist

        vector<int>dis(n,1e9);

        dis[src]=0;

        while(!pq.empty())
        {
            auto it = pq.top(); pq.pop();
            auto src = it[1];
            auto cost = it[2];
            auto stops = it[0];

            if(stops==k+1) continue;

            for(auto & x : adj[src])
            {
                if(dis[x.first]>cost+x.second)
                {
                    dis[x.first] = cost+x.second;
                    pq.push({stops+1,x.first,dis[x.first]});
                }
            }
        }

        return dis[dst]==1e9?-1:dis[dst];
        
    }
};
