/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
       priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;

       for(auto & x : intervals)
       {
            pq.push({x.start,1});
            pq.push({x.end,0});
       }

       int curr=0,ans=0;

       while(!pq.empty())
       {
            auto it = pq.top(); pq.pop();

            if(it.second==1) curr++;
            else curr--;

            ans = max(ans,curr);
       }

       return ans;
    }
};
