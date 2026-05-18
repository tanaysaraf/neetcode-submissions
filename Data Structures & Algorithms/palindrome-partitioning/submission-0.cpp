class Solution {
public:
vector<vector<string>>ans;

    bool isPal(string s)
    {
        string rs = s;
        reverse(begin(rs), end(rs));
        return rs==s;
    }
    void solve(string s, int i, vector<string>parts)
    {
        if(i==s.size())
        {
            ans.push_back(parts);
            return;
        }

        for(int j=i;j<s.size();j++)
        {
            string left = s.substr(i, j-i+1);
            if(isPal(left))
            {
                parts.push_back(left);
                solve(s,j+1,parts);
                parts.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ans.clear();
        solve(s,0,{});
        return ans;
    }
};
