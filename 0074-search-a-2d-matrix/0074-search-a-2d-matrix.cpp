class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int l = 0, r= row-1, p;
        while(l<=r){
            int m = l + (r-l)/2;
            if(matrix[m][0] <= target && target <= matrix[m][col-1]) {
                p = m;
                break;
            }
            else if(matrix[m][0] > target) r = m-1;
            else l = m + 1;
        }

        l = 0, r = col-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(matrix[p][m] == target) return true;
            else if(matrix[p][m] > target) r = m-1;
            else l = m+1;
        }
        return false;

    }
};