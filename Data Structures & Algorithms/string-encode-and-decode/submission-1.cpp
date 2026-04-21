class Solution {
public:
  
    string del = "#";

    string encode(vector<string>& strs) {

        string ans = "";
        for(auto & x : strs)
        {
            int len = x.size();
            ans+=to_string(len)+del+x+del;
        }

        return ans;
    }

    vector<string> decode(string s) {

        string prev = "";
        vector<string>ans;
        int i = 0;
        while(i<s.size())
        {
            while(i< s.size() && s[i]!='#')
            {
                prev+=s[i++];
            }

            int len = stoi(prev);
            prev="";

            i++; // skips the delimeter after length.

            while(len--)
            {
                prev+=s[i++];
            }
            ans.push_back(prev);
            prev="";
            i++; // skips the delimeter

        }

        return ans;


    }
};
