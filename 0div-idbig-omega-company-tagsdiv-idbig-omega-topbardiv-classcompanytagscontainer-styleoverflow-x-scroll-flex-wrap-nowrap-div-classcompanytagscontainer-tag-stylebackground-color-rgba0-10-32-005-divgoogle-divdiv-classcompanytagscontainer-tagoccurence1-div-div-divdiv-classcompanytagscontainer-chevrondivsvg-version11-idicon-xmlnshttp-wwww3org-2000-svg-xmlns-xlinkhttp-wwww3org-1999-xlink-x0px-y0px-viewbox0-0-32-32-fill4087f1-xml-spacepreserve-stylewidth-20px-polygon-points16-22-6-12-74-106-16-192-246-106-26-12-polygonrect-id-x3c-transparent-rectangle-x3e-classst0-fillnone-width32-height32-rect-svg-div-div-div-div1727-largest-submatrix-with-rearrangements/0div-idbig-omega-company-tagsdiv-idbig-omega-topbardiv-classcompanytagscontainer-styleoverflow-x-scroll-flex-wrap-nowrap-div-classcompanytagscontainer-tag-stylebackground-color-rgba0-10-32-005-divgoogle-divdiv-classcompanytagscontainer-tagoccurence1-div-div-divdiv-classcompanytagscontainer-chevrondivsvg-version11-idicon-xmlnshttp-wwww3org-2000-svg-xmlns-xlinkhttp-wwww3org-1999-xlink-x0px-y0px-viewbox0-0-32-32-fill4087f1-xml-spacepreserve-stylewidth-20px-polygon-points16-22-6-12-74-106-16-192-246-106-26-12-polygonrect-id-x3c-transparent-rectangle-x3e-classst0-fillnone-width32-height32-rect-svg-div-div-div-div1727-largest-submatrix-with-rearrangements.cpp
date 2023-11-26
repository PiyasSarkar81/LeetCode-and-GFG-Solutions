class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int max_area = 0;
        for(int i = 0; i < n; i++){
            // update the height array
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1) height[j]++;
                else height[j] = 0;
            }
            // sort the height array, because we can rearrange the column
            vector<int> sorted_height = height;
            sort(sorted_height.begin(), sorted_height.end());
            // find the max_area
            for(int j = 0; j < m; j++){
                int curr_area = sorted_height[j] * (m - j);
                max_area = max(max_area, curr_area);
            }
        }
        return max_area;
    }
};