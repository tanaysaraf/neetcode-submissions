class Solution {
public:
    int GetNew(int n)
    {
        int ans=0;
        int cpy = n;
        while(cpy)
        {
            int d= cpy%10;
            cpy/=10;
            ans+=d*d;
        }

        return ans;
    }
    bool isHappy(int n) {

        set<int>vis;
        while(true)
        {
            int newNumber = GetNew(n);
            cout<<n<<" "<<newNumber<<endl;
            if(newNumber==1) return true;
            if(vis.find(newNumber)!=vis.end()) return false;
            vis.insert(newNumber);
            n = newNumber;
        }

        return false;
        
    }
};
