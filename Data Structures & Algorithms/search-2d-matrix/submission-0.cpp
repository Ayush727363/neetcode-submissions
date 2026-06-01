class Solution {
public:
    int bsr(int l, int r, int t, vector<vector<int>>& mat){
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(mat[mid][0] <= t && t <= mat[mid].back()) break;
            else if(mat[mid][0] < t) l = mid+1;
            else r = mid-1;
        }
        return mid;
    }

    bool bsc(int l, int r, int t, vector<vector<int>>& mat, int row){
        int mid;
        while(l<=r){
            mid = (l+r)/2;
            if(mat[row][mid] == t) return true;
            else if(mat[row][mid] < t) l = mid+1;
            else r = mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = bsr(0, matrix.size()-1, target, matrix);
        return bsc(0, matrix[0].size()-1, target, matrix, row);
    }
};
