class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = (nums1[i-1] == nums2[j-1]) ? dp[i-1][j-1] + 1 : max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[n][m];
    }
};