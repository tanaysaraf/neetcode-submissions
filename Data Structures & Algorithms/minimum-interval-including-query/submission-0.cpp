class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        sort(begin(intervals), end(intervals));


        for(auto & x : intervals)
        {
            cout<<x[0]<<" "<<x[1]<<endl;
        }
        // sorted by starting date. 
        vector<int>ret;
        for(auto &x : queries)
        {
            int it = upper_bound(

    intervals.begin(),

    intervals.end(),

    x,

    [](int val, const vector<int>& interval) {

        return val < interval[0];

    }

) - intervals.begin();
 it--;

            cout<<it<<endl;

            int ans = 1e9;
            while(it>=0)
            {
                if(intervals[it][0]<=x && intervals[it][1]>=x)
                    ans = min(ans, intervals[it][1]-intervals[it][0]+1);

                it--;
            }
            if(ans==1e9) ans=-1;
            ret.push_back(ans);
        }

        return ret;
        
    }
};
