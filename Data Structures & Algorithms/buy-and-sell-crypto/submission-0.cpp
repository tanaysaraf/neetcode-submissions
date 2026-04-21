class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int prev = 1e9;
        int ans = 0;
        for(auto & x : prices)
        {
            prev = min(prev,x);
            ans = max(ans, x-prev);
        }

        return ans;
        
    }
};
