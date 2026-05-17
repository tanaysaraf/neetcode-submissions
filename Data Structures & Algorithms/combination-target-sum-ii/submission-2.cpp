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

        if(nums[i]<=target)
        {
            subset.push_back(nums[i]);
            solve(nums,i+1,subset,target-nums[i]);
            subset.pop_back();
        }

        int ind = i;

        while(ind<nums.size() && nums[i]==nums[ind]) ind++;

        solve(nums,ind,subset,target);
        

        

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        ans.clear();
        sort(begin(nums),end(nums));
        solve(nums,0,{}, target);



        return ans;
    }
};
