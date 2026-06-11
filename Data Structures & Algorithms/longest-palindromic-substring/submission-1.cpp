class Solution {
public:
    string longestPalindrome(string s) {


        int n = s.size();
        int maxLen=0;
        string ans="";

        for(int i=0;i<n;i++)
        {
            // expand centre 

            int j=i,k=i;
            int len = 0;
            while(j>=0 and k<n)
            {
                if(s[j]!=s[k]) break;
                if(j==k)len++;
                else len+=2;

                j--,k++;
            }

            if(len>maxLen)
            {
                maxLen = len;
                ans = s.substr(j+1,maxLen);
            }
        }
       // cout<<"ans "<<maxLen<<endl;
        // expand accross middle like for cases bb 

        for(int i=1;i<n;i++)
        {
            int j = i-1;
            int k = i;
            int len = 0;
            if(s[j]!=s[k]) continue;
            while(j>=0 and k<n and s[j]==s[k]){
              //  cout<<"in here";
j--,k++,len+=2;
            } 

            //cout<<len<<endl;
            if(len>maxLen)
            {
                cout<<j<<" "<<k<<" "<<len<<endl;
                maxLen = len;
                ans = s.substr(j+1,len);
            }
        }

        return ans;
        
    }
};
