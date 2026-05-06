class Solution {
public:
    int findMin(vector<int> &nums) {
        
        int n = nums.size();
        int s = 0 , e= nums.size()-1;

        // if(nums[s]<nums[e]) return s;
        // if(nums[e]<nums[e-1]) return e;

        if(n>1 and nums[e]<nums[e-1]) return nums[e];
        if(n>1 and nums[0]<nums[e]) return nums[0];
        while(s<=e)
        {
            int m = (s+e)/2;

            //if(m>0 and m<nums.size()-1 and nums[m]<nums[m-1] and nums[m]<nums[m+1]) return nums[m];

            int left = (m==0) ? -1 : nums[m-1];
            int right = (m==n-1) ? 1e9 : nums[m+1];

            if(nums[m]<left and nums[m]<right) return nums[m];

            if(nums[s]<nums[e])
            {
                // entire section is sorted
                e = m-1;
            }
            else
            {
                if(nums[m]>=nums[s]) s = m+1;
                else
                e = m-1;
            }

        }
        cout<<"here "<<e<<endl;
        return nums[e];
    }
};
