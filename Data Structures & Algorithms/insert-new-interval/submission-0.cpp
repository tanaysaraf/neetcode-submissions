class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        intervals.push_back(newInterval);
        sort(begin(intervals), end(intervals));


        vector<vector<int>>ans;

        int l = intervals[0][0];
        int r = intervals[0][1];

        for(int i=1;i<intervals.size();i++)
        {
            // check if non overlapping or not
            //cout<<"I "<<intervals[i][0]<<" & "<<intervals[i][1]<<endl;

            if(r<intervals[i][0])
            {
                // add previous
                ans.push_back({l,r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else
            {
                r = max(r, intervals[i][1]);
                //cout<<"Overlap "<<intervals[i][0]<<" & "<<intervals[i][1]<<endl;
            }
        }
        ans.push_back({l,r});

        return ans;

    }
};
