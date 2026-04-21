class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int>ans;
        map<int,int>mp;
        for(auto & x : nums)
        mp[x]++;

        priority_queue<pair<int,int>>pq;

        for(auto & x : mp)
        {
            pq.push({x.second,x.first});
        }

        while(k--)
        {
            if(pq.size()==0) break;
            int num = pq.top().second; pq.pop();
            ans.push_back(num);
        }

        return ans;
        
    }
};
