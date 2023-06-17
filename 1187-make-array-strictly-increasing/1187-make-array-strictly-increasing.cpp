class Solution {
    int dfs(int i, int pre, int c, int n, int m, vector<int> &arr1, vector<int> &arr2, vector<vector<vector<int>>> &dp) {
        if(i == n) return 0;
        if(dp[i][pre][c] != -1) return dp[i][pre][c];

        if(i == 0) {
            int notpick = dfs(i + 1, i, 1, n, m, arr1, arr2, dp);
            int pick = 1 + dfs(i + 1, 0, 2, n, m, arr1, arr2, dp);
            return dp[i][pre][c] = min(pick, notpick);
        }

        int last = c == 1 ? arr1[pre] : arr2[pre];
        if(last >= arr1[i]) {
            int pick = 1e9;
            int pos = upper_bound(arr2.begin(), arr2.end(), last) - arr2.begin();
            if(pos < m) pick = 1 + dfs(i + 1, pos, 2, n, m, arr1, arr2, dp);
            return dp[i][pre][c] = pick;
        }

        int notpick = dfs(i + 1, i, 1, n, m, arr1, arr2, dp);
        int pick = 1e9;
        int pos = upper_bound(arr2.begin(), arr2.end(), last) - arr2.begin();
        if(pos < m) pick = 1 + dfs(i + 1, pos, 2, n, m, arr1, arr2, dp);

        return dp[i][pre][c] = min(pick, notpick);
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        sort(arr2.begin(), arr2.end());
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(max(n, m), vector<int>(3, -1)));

        int ans = dfs(0, 0, 0, n, m, arr1, arr2, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};