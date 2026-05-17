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

        // dont pick
        solve(nums,i+1,subset);

        subset.push_back(nums[i]);
        solve(nums,i+1,subset);
        subset.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.clear();
        solve(nums, 0, {});
        
        return ans;
    }
};
