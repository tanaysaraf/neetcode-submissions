class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<pair<int,char>>pq;

        vector<int>taskF(26,0);

        for(auto & x : tasks)
        {
            taskF[x-'A']++;
        }

        for(int i=0;i<26;i++)
        {
            if(taskF[i]==0) continue;

            pq.push({taskF[i],i+'A'});
        }

        int ans=0;


        int debug=5;
        
        int lastIdle=0;
        while(pq.size()>0)
        {
            vector<pair<int,char>>vec;
            int used=0;
            for(int i=0;i<=n && pq.size()>0;i++)
            {
                auto ele = pq.top(); pq.pop();
                ele.first--;
                //cout<<ele.second<<" ";
                if(ele.first>0) vec.push_back(ele);
                used++;
            }

            int rem = n+1-used;
            lastIdle = rem;

            // rem idle cycles
            //cout<<rem<<" idle \n";

            //cout<<endl;
            // we need to add something to ans 
            ans+=n+1;

            cout<<vec.size()<<endl;
            for(auto & x : vec)
            pq.push(x);

        }

        if(pq.size()==0) ans-=lastIdle;

        if(pq.size()>0)
        {
             auto ele = pq.top(); pq.pop();
             int cnt = ele.first;

             ans+=(cnt-1)*n + cnt;
        }

        return ans;
        
        
    }
};
