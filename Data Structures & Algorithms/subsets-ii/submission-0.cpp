class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, int i, vector<int>subset)
    {
        if(i==nums.size())
        {
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        solve(nums,i+1,subset);
        subset.pop_back();

        // dont pick
        int ind = i;

        while(ind<nums.size() && nums[ind]==nums[i]) ind++;
        solve(nums,ind,subset);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        sort(begin(nums), end(nums));
        solve(nums,0,{});

        return ans;
    }
};
