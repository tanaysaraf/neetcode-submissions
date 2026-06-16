class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int>vec;

        for(auto & x : nums)
        {
            if(vec.size()==0 or vec.back()<x) {
                vec.push_back(x);
                continue;
            }

            auto it = lower_bound(vec.begin(), vec.end(), x) - vec.begin();

            vec[it]=x;
        }

        return vec.size();
        
    }
};
