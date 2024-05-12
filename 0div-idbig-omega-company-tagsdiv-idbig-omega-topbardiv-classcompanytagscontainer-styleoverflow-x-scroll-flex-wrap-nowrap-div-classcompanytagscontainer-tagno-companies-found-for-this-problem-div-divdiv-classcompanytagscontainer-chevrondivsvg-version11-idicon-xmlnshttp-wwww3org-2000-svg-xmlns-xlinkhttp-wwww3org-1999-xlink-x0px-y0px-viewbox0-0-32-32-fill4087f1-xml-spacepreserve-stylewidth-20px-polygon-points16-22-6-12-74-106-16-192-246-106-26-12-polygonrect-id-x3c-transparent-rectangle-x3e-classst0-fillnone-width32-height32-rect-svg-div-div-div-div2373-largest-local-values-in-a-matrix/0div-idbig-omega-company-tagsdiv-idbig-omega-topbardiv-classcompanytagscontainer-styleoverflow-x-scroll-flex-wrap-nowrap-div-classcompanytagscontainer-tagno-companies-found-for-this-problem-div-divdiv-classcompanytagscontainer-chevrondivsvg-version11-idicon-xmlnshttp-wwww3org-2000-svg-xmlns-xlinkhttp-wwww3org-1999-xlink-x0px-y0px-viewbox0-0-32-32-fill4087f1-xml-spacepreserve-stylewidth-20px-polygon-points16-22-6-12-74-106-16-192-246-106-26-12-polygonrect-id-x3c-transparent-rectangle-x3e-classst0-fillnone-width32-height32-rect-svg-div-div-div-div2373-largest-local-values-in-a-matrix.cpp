class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        int rowsOf_grid = grid.size();
        int colsOf_grid = grid[0].size();
        int rowsOf_ans = grid.size() - 2;
        int colsOf_ans = grid[0].size() - 2;
        ans.resize(rowsOf_ans, vector<int>(colsOf_ans));

        for (int rowsA = 0; rowsA < rowsOf_ans; rowsA++) {
            for (int colsA = 0; colsA < colsOf_ans; colsA++) {
                int max = 0;

                for (int rowsG = rowsA; rowsG < rowsA + 3; rowsG++) {
                    for (int colsG = colsA; colsG < colsA + 3; colsG++) {
                        if (max < grid[rowsG][colsG]) {
                            max = grid[rowsG][colsG];
                        }
                    }
                }

                ans[rowsA][colsA] = max;
            }
        }
        return ans;
    }
};