class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // TC -> O(n^2) and SC -> O(n^2)
        
//         int n = matrix.size(), m = matrix[0].size();
//         vector<vector<int>> ans(n, vector<int> (m));

//         for(int i =0;i<n;i++) {
//             for(int j = 0; j<m; j++) {
//                 ans[i][j] = matrix[n-1-j][i];
//             }
//         }

//         for(int i =0;i<n;i++) {
//             for(int j = 0;j<m;j++) {
//                 matrix[i][j] = ans[i][j];
//             }
//         }
        
        
//  TC -> O(n/2 * n/2) +  O(n * n/2) SC -> O(1) 
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j = 0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i =0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};