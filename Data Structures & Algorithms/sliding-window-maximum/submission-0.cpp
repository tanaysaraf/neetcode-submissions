class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq; // store indices. 
        // insert from back, use from front

        vector<int>ans;

        int s = 0 , e=0, n = nums.size();

        while(e<n)
        {
            if(dq.size()>0 and dq.front()<s) dq.pop_front();
            while(dq.size()>0 and nums[dq.back()]<=nums[e]) dq.pop_back();
            dq.push_back(e);
            e++;

            if(e>=k)
            {
                ans.push_back(nums[dq.front()]);
                s++;
            }
        }

        return ans;
        
    }
};
