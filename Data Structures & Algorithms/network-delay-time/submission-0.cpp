class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dis(n+1,1e9);
        vector<pair<int,int>>adj[101];

        for(auto & x : times)
        {
            auto u = x[0];
            auto v = x[1];
            auto cost = x[2];

            adj[u].push_back({v,cost});
        }

        dis[k]=0;

        pq.push({0,k});

        while(!pq.empty())
        {
            auto it = pq.top(); pq.pop();

            auto src = it.second;
            auto cost = it.first;

            for(auto & x : adj[src])
            {
                if(dis[x.first]>cost+x.second)
                {
                    dis[x.first] = cost+x.second;
                    pq.push({dis[x.first], x.first});
                }
            }
        }

        // for(auto & x : dis)
        // cout<<x<<" ";
        // cout<<endl;

        int maxTime = *max_element(begin(dis)+1,end(dis));
        if(maxTime==1e9) return -1;
        return maxTime;
    }
};
