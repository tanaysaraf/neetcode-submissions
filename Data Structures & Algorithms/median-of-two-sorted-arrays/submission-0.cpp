class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // we will consider n < m
        int n = nums1.size(), m = nums2.size();

        if(n>m) return findMedianSortedArrays(nums2, nums1);

        int l = 0 , r = n; // number of elements I take from nums1 

        int ctr = 10;
        while(l<=r)
        {
           int takenFrom1 = (l+r)/2;

           //cout<<takenFrom1<<" ";

           int takenFrom2 = (n+m)/2 - takenFrom1;

           int ind1 = takenFrom1-1;
           int ind2 = takenFrom2-1;

           int ul = (ind1==-1) ? -1e9 : nums1[ind1];
           int ur = (ind1==n-1) ? 1e9 : nums1[ind1+1];

           int dl = (ind2==-1) ? -1e9 : nums2[ind2];
           int dr = (ind2==m-1) ? 1e9 : nums2[ind2+1];

           if(ul<=dr && dl<=ur)
           {

            cout<<takenFrom1<<" "<<takenFrom2<<" "<<ul<<" "<<ur<<" "<<dl<<" "<<dr<<endl;
            if((n+m)%2==0)
            {
                return (max(ul,dl)+min(ur,dr))/2.0;
            }

            else
            {
                return 1.0*(min(ur,dr));
            }
           }

           else if(ul>dr)
           r = takenFrom1-1;

           else
           l = takenFrom1+1;
        }
        return 0.0;
        
    }
};
