class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;

        map<char,char>mp;
        mp[')']='(';
        mp[']']='[';
        mp['}']='{';

        for(auto & x : s)
        {
            if(x=='(' or x=='[' or x=='{')
            {
                st.push(x);
            }
            else
            {
                auto pairType = mp[x];

                if(st.size()==0) return false;
                if(st.top()!=pairType) return false;

                st.pop();
            }
        }

        return st.size()==0;
    }
};
