class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>s(nums.begin(), nums.end()); // O(n) ?

        int len = 0;
        for(auto & x : nums)
        {
            if(s.find(x+1)!=s.end()) continue;

            int cnt = 1;
            int num = x;
            while(s.find(x-1)!=s.end())
            {
                x--;
                cnt++;
            }

            len = max(len,cnt);
        }

        return len;
    }
};
