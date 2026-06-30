class Solution {
public:

    static bool cmp(vector<int>&a, vector<int>&b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(begin(intervals), end(intervals), cmp);

        int prev = 0;
        int removed=0;
        for(int i=1;i<intervals.size(); i++)
        {
            if(intervals[i][0]<intervals[prev][1])
            {
                // overlap so ignore
                removed++;

            }
            else
            {
                prev = i;
            }
        }

        return removed;
    }
};
