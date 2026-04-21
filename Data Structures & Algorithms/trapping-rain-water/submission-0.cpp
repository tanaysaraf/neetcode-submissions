class Solution {
public:
    int trap(vector<int>& height) {

        int lmax=0,hmax=0,ans=0;
        int i = 0 , j = height.size()-1;

        while(i<=j)
        {
            hmax = max(hmax, height[j]);
            lmax = max(lmax, height[i]);

            ans+=hmax-height[j];
            ans+=lmax-height[i];

            if(height[i]<=height[j]) i++;
            else j--;
        }

        return ans;
        
    }
};
