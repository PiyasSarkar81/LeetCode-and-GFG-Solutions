class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        int dp[110][110] = {};
        for(int i=1;i<=n;i++){
            for(int j=0;j<=i && j<=k;j++){
                int needRemove = 0, groupCount = 0;
                dp[i][j] = INT_MAX;
                if(j) dp[i][j] = dp[i-1][j-1];
                for(int l=i;l>=1;l--){
                    if(s[l-1] != s[i-1]) needRemove++;
                    else groupCount++;
                    if(needRemove > j) break;
                    if(groupCount == 1) dp[i][j] = min(dp[i][j],dp[l-1][j-needRemove]+1);
                    else if(groupCount < 10) dp[i][j] = min(dp[i][j],dp[l-1][j-needRemove]+2);
                    else if(groupCount < 100) dp[i][j] = min(dp[i][j],dp[l-1][j-needRemove]+3);
                    else dp[i][j] = min(dp[i][j],dp[l-1][j-needRemove]+4);
                }
            }
        }
        return dp[n][k];
    }
};