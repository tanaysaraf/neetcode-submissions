class Solution {
public:
vector<vector<int>> ans;
    void solve(vector<int>&nums, vector<int>perm)
    {
        if(perm.size()==nums.size())
        {
            ans.push_back(perm);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==-11)
            continue;

            int val = nums[i];
            nums[i]=-11;
            perm.push_back(val);
            solve(nums,perm);
            perm.pop_back();
            nums[i]=val;


        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, {});
        return ans;
    }
};
