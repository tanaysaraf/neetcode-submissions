class Solution {
public:
    int characterReplacement(string str, int k) {

        int n = str.size();
        int ans = 0;
        for(char ch = 'A'; ch<='Z'; ch++)
        {
            // ch will be the character that is supposed to occur. 

            int s=0,e=0,len=0,maxLen=0;
            int diff = 0;

            while(e<n)
            {
                if(str[e]!=ch) diff++;
                e++;
                if(diff<=k)
                len++;

                else
                {
                    if(str[s]!=ch) diff--;
                    s++;
                }

                maxLen = max(maxLen,len);
            }

            ans = max(ans, maxLen);
        }

        return ans;
        
    }
};
