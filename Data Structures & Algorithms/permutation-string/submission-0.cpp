class Solution {
public:
    bool compare(vector<int>&v1, vector<int>&v2)
    {
        return v1==v2;
    }
    bool checkInclusion(string s1, string s2) {
        
        vector<int>v1(26,0);
        vector<int>v2(26,0);

        for(auto &x : s1)
        v1[x-'a']++;

        int s=0,e=0;

        while(e<s2.size())
        {
            v2[s2[e++]-'a']++;

            if(e-s==s1.size())
            {
                //auto sub = s2.substr(s,e-s);

              

                
                if(compare(v1,v2)) return true;

                v2[s2[s++]-'a']--;
            }
            
        }

        return false;
    }
};
