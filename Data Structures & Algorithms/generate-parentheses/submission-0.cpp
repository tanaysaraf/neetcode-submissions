class Solution {
public:
    vector<string>ans;
    void solve(int o, int c, string s)
    {
        if(o==0 and c==0)
        {
            ans.push_back(s);
            return;
        }


        if(o>0)
        solve(o-1,c,s+"(");

        if(c>0 and c>o)
        solve(o,c-1,s+")");

    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        solve(n,n,"");
        return ans;
    }
};
