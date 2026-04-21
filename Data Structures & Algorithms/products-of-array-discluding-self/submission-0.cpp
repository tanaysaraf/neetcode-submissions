class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int>post(n,1);
        post[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            post[i]=post[i+1]*nums[i];
        }

        int pre = 1;
        vector<int>ans(n);

        for(int i=0;i<n-1;i++)
        {
            ans[i] = pre * post[i+1];
            pre*=nums[i];
        }

        ans[n-1] =  pre;

        return ans;



    }
};
