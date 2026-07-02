class Solution {
public:

    double solve(double x, int n)
    {
        if(n==0) return 1.0;
        if(n==1) return x;

        auto half = solve(x,n/2);

        if(n%2==1)
        return half*half*x;

        return half*half;
    }
    double myPow(double x, int n) {
        
        if(n<0)
        {
            auto ans = solve(x,-1*n);
            return 1/ans;
        }
        return solve(x,n);
    }
};
