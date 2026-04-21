class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>>mp;

        for(auto  x : strs)
        {
            auto par = x;
            sort(begin(par),end(par));
            mp[par].push_back(x);
        }

        vector<vector<string>>ans;

        for(auto & x : mp)
        {
            ans.push_back(x.second);
        }

        return ans;
    }
};
