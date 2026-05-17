class Solution {
public:
vector<vector<int>>ans;
    void solve(vector<int>&nums, int i, vector<int>subset, int target)
    {
        if(target==0)
        {
            ans.push_back(subset);
            return;
        }
        if(i==nums.size()) {
            

            return;
        }

        solve(nums,i+1,subset,target);
        
        if(nums[i]<=target)
        {
            subset.push_back(nums[i]);
            solve(nums, i, subset, target-nums[i]);
            subset.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums, 0, {}, target);
        return ans;
    }
};
