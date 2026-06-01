class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int m = mat.size();
        int n = mat[0].size();

        int l = 0, r = m*n-1;

        while(l <= r){
            int mid = (l+r)/2;
            
            int row = mid / n;
            int col = mid % n;

            if(mat[row][col] == t) return true;
            else if(mat[row][col] < t) l = mid+1;
            else r = mid-1;
        }
        return false;
    }
};
