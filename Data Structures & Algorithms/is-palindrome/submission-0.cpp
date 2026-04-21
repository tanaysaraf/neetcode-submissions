class Solution {
public:

    bool isAlphaNumberic(char ch)
    {
        if(toupper(ch)>='A' && toupper(ch)<='Z') return 1;
        if(ch>='0' and ch<='9') return 1;
        return 0;
    }
    bool isPalindrome(string s) {


        int i = 0, j = s.size()-1;

        while(i<=j)
        {
            while(i<=j && !isAlphaNumberic(s[i])) i++;
            while(j>=i && !isAlphaNumberic(s[j])) j--;
            if(i>j) break;

            if(toupper(s[i])!=toupper(s[j])) {
                cout<<i<<" "<<j<<endl;
                return false;
            }
            i++;
            j--;
        }

        return true;
        
    }
};
