class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        int s = 0;
        int e = m*n-1;

        while(s<=e)
        {
            int mid = s + (e - s) / 2;

            int r = mid / m;
            int c = mid % m;

            if(target==matrix[r][c]) return 1;



            if(target>matrix[r][c]) s = mid+1;

            else
            e = mid-1;
        }

        return false;

        
    }
};
