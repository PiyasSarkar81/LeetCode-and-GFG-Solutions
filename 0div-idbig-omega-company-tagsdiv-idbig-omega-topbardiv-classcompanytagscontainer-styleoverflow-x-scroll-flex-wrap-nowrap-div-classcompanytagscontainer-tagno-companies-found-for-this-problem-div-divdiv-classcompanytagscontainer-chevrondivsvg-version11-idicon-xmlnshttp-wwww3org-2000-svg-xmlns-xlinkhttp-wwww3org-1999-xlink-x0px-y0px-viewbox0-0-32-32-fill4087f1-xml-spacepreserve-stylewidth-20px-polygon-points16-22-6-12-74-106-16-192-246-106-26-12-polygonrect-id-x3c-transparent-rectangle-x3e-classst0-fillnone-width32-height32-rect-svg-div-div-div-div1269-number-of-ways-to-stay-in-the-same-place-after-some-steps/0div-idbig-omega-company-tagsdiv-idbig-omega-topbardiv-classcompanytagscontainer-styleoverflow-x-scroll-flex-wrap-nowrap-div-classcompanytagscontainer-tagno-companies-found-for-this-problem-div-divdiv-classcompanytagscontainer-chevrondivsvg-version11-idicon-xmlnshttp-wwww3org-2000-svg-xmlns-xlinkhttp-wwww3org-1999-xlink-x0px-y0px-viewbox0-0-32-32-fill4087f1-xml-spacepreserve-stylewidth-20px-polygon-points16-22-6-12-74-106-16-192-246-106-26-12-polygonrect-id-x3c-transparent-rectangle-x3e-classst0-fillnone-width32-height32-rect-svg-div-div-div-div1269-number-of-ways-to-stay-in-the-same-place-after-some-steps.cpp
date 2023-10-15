class Solution {
public:
    int mod = 1e9+7;
    int numWays(int steps, int arrLen) {
        int n = min(steps/2+1, arrLen);
        vector<vector<int>> dp(steps+1,vector<int>(n,0));
        dp[0][0] = 1;
        for(int i=1;i<=steps;i++){
            for(int j =0;j<n;j++){
                dp[i][j] = dp[i-1][j];
                if(j>0){
                    dp[i][j] = (dp[i][j]+dp[i-1][j-1])%mod;
                }
                if(j<n-1) dp[i][j] = (dp[i][j]+dp[i-1][j+1])%mod;
            }
        }
        return dp[steps][0];
    }
};