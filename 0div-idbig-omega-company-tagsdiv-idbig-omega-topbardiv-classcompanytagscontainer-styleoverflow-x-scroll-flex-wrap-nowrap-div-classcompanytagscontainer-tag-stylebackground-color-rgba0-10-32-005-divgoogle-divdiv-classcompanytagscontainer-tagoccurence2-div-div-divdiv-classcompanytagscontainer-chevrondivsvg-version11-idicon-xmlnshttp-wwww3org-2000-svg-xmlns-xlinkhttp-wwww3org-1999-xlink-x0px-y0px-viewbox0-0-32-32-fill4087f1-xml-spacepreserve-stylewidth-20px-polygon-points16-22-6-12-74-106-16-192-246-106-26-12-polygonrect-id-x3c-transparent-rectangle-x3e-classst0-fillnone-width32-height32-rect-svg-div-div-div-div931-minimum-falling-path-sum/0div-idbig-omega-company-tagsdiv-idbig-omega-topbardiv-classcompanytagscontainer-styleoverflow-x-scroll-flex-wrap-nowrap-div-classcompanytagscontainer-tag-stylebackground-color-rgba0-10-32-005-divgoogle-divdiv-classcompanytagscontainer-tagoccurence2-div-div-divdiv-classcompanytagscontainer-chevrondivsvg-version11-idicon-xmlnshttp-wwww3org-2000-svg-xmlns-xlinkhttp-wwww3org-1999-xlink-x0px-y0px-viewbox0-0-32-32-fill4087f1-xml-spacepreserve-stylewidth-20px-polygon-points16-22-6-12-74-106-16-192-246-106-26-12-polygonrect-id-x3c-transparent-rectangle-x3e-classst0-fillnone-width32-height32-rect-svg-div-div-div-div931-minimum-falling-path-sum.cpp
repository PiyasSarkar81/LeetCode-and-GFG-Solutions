class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> curr(m,0), prev(m,0);
        for(int j=0;j<m;j++) prev[j] = matrix[0][j];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int ld = 1e9,rd = 1e9;
                int up = matrix[i][j]+prev[j];
                if(j-1 >= 0)
                    ld = matrix[i][j] + prev[j-1];
                if(j+1 < m) rd = matrix[i][j] + prev[j+1];
                curr[j] = min(up,min(ld,rd));
                
            }
            prev = curr;
        }
        int mini = prev[0];
        for(int j=1;j<m;j++)
            mini = min(mini,prev[j]);
        return mini;
    }
};