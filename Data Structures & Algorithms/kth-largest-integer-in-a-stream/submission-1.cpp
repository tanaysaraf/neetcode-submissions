class KthLargest {
public:
priority_queue<int, vector<int>,greater<int>>pq;
int kk;
    KthLargest(int k, vector<int>& nums) {
        kk=k;
        for(auto & x : nums) {
            pq.push(x);
        }

        while(pq.size()>k) pq.pop();
    }
    
    int add(int x) {
        
            pq.push(x);
            if(pq.size()>kk)pq.pop();

             return pq.top();
    }
};
