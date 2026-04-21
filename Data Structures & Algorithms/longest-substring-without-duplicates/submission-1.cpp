class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        
        vector<int>li(260,-1);
        int ans = 0;
        int n = str.size();
        int s=0,e=0;

        while(e<n)
        {
            if(li[str[e]]==-1 or li[str[e]]<s)
            {
                li[str[e]]=e;
                e++;
            }
            else
            {
                s = li[str[e]]+1;
            }

            ans = max(ans,e-s);
        }

        return ans;
    }
};
