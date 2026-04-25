class Solution {
public:

bool IsSubstet(vector<int>&v1, vector<int>&v2)
{
    for(int i=0;i<260;i++)
    {
        if(v2[i]<v1[i]) return false;
    }
    return true;
}
    string minWindow(string str, string t) {
        
        vector<int>v1(260,0);
        vector<int>v2(260,0);

        if(t.size()>str.size()) return "";

        for(auto & x : t)
        {
            v1[x-'A']++;
        }

        int s=0,e=0, ans=str.size();
        string ret = "";

        while(e<str.size())
        {
            v2[str[e++]-'A']++;

            while(IsSubstet(v1,v2))
            {
                if(ans>=e-s)
                {
                    cout<<"len "<<e-s<<endl;
                    ret = str.substr(s,e-s);
                    ans = e-s;
                }
                v2[str[s++]-'A']--;
            }

        }

         while(IsSubstet(v1,v2))
            {
                if(ans>=e-s)
                {
                    ret = str.substr(s,e-s);
                    ans = e-s;
                }
                v2[str[s++]-'A']--;
            }

        return ret;
    }
};
