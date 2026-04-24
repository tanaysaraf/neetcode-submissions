class Solution {
public:
    int characterReplacement(string str, int k) {

        int s=0,e=0,len=0,ans=0,maxf=0;
        vector<int>frq(26,0);
        int n = str.size();
        while(e<n)
        {
            frq[str[e]-'A']++;
            maxf = max(maxf,frq[str[e]-'A']);
            len++; 
            e++;

            if(len-maxf<=k)
            {
                ans = max(ans,len);
            }
            else
            {
                frq[str[s]-'A']--;
                len--;
                s++;
            }
        }

        return ans;
        
    }
};
