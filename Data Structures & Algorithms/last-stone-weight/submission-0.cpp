class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {

        priority_queue<int>pq(begin(nums),end(nums));

        while(pq.size()>1)
        {
            auto e1 = pq.top(); pq.pop();
            auto e2 = pq.top(); pq.pop();

            if(e1==e2) continue;
            else
            pq.push(e1-e2);
        }

        return pq.size()==0 ? 0 : pq.top();
        
    }
};
