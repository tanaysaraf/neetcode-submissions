class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        

        // NGR 

        stack<int>s; // store indices.

         int n = temperatures.size();
        vector<int>ans(n);

       
        for(int i = n-1;i>=0;i--)
        {
            while(s.size()>0 and temperatures[s.top()]<=temperatures[i]) s.pop();

            if(s.size()==0)
            ans[i]=0;

            else
            ans[i] = s.top()-i;

            s.push(i);
        }
        return ans;

    }
};
