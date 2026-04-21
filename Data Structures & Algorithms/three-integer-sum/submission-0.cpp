class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {


        sort(begin(nums),end(nums));
        int n = nums.size();
        set<vector<int>>s;
        for(int i=0;i<n-2;i++)
        {
            int tar = -nums[i];

            int j=i+1,k=n-1;

            while(j<k)
            {
                int sum = nums[j]+nums[k];

                if(sum==tar)
                {
                    s.insert({nums[i],nums[j],nums[k]});
                    j++,k--;
                }
                else if(sum>tar) k--;
                else j++;
            }
        }

        vector<vector<int>>ans;

        for(auto it = s.begin(); it!=s.end(); it++)
        {
            ans.push_back(*it);
        }

        return ans;
        
    }
};
