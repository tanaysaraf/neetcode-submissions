class Solution {
public:

    bool fun(int m, vector<int>& piles, int h)
    {
        // m is minimum banana eaten per file.
        int ti = 0;
        if(m==0) return false;
        for(auto & x : piles)
        {
            ti+=ceil(x/(m*1.0));
            if(ti>h) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int s = 0;
        int e = *max_element(begin(piles), end(piles));
        int ans = e;
        while(s<=e)
        {
            int m = (s+e)/2;

            if(fun(m, piles, h))
            {
                cout<<m<<" is valid"<<endl;
                ans = m;
                e = m-1;
            }
            else
            {
                s = m+1;
            }
        }
        return ans;
        
    }
};
