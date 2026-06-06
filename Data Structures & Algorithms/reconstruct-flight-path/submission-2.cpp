class Solution {
public:
unordered_map<string,vector<string>>adj;
vector<string>ans;

    bool solve(string node, int tickets, vector<string>&res)
    {
        if(tickets==0) {
            ans = res;
            return true;
        }

        if(adj[node].size()==0) return false;

         vector<string> temp = adj[node];
        for (int i = 0; i < temp.size(); ++i) {
            string v = temp[i];
            adj[node].erase(adj[node].begin() + i);
            res.push_back(v);
            if (solve(v, tickets-1, res)) return true;
            adj[node].insert(adj[node].begin() + i, v);
            res.pop_back();
        }

        return false;


    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        sort(tickets.begin(), tickets.end());
        for(auto & x : tickets)
        {
            adj[x[0]].push_back(x[1]);
        }

        vector<string>path {"JFK"};
        solve("JFK", tickets.size(), path);

        return ans;


    }
};
