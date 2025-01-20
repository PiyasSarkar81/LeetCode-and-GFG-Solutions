class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();

        unordered_map<int, pair<int, int>> mp;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                mp[mat[row][col]] = {row, col};
            }
        }

        vector<int> rowCount(m, 0), colCount(n, 0);

        for (int i = 0; i < arr.size(); ++i) {
            int val = arr[i];
            auto pos = mp[val];
            int row = pos.first, col = pos.second;

            rowCount[row]++;
            colCount[col]++;

            if (rowCount[row] == n || colCount[col] == m) {
                return i;
            }
        }

        return -1;
    }
};