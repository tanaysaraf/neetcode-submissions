class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n = s.size();
        vector<int>lastIndex(26,0);
        vector<int>ans;
        int last=0;
        for(int i=0;i<n;i++)
        {
            lastIndex[s[i]-'a'] = max(lastIndex[s[i]-'a'], i);
            //cout<<lastIndex[s[i]-'a']<<endl;
        }
        int i=0;
        int len=0;
        for(auto & x : s)
        {
            len++;
            int last = max(last,lastIndex[x-'a']);
            //cout<<last<<endl;

            if(last==i)
            {
                // we got a partition
                ans.push_back(len);
                len=0;
            }
            i++;
        }

        return ans;
        
    }
};
