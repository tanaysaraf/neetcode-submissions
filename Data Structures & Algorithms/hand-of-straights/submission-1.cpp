#define pii pair<int,int>
class Solution {
public:

    bool isNStraightHand(vector<int>& hand, int groupSize) {

        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<int>frq(1001,0);
        for(auto & x : hand) frq[x]++;

        for(int i=0;i<1001;i++)
        {
            if(frq[i]==0) continue;

            pq.push({i,frq[i]});
        }

        while(pq.size()>=groupSize)
        {
            int n = groupSize;

            if(pq.size()<n) return false;

            vector<pii>vec;

            while(n--)
            {
                vec.push_back(pq.top());
                pq.pop();
            }
            int prev = -1;
            //cout<<" size "<<vec.size()<<endl;

            for(int i=0;i<vec.size();i++)
            {
                if(i>0 and vec[i].first-prev!=1) return false;
                //cout<<prev<<" "<<vec[i].first<<endl;
                if(vec[i].second>1) pq.push({vec[i].first,vec[i].second-1});
                prev = vec[i].first;
            }
        }

        if(pq.size()>0) return false;

        return true;
        
    }
};
// 1 2 2 3 3 4 4 5
