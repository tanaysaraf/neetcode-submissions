class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = -1e9,curr=0;

        for(auto & x : nums)
        {
            curr = max(curr+x,x);
            ans = max(ans,curr);
        }

        return ans;

    }
};
