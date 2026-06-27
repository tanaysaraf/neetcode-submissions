class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        vector<int>trips(3,-1);

        vector<vector<int>> vec;

        for(auto & x : triplets)
        {
            bool flag = true;
            for(int i=0;i<3;i++)
            {
                if(x[i]>target[i]) {
                   // cout<<"REMOVED\n";
                    flag = false;
                    break;
                }
            }

            if(!flag) continue;

            vec.push_back(x);
        }

        for(auto & x : vec)
        {
            for(int i=0;i<3;i++)
            {
                trips[i] = max(trips[i], x[i]);
            }

        }

        for(int i=0;i<3;i++)
        {
           // cout<<trips[i]<<" ";
            if(trips[i]!=target[i]) return false;
        }

        return true;
    }
};
