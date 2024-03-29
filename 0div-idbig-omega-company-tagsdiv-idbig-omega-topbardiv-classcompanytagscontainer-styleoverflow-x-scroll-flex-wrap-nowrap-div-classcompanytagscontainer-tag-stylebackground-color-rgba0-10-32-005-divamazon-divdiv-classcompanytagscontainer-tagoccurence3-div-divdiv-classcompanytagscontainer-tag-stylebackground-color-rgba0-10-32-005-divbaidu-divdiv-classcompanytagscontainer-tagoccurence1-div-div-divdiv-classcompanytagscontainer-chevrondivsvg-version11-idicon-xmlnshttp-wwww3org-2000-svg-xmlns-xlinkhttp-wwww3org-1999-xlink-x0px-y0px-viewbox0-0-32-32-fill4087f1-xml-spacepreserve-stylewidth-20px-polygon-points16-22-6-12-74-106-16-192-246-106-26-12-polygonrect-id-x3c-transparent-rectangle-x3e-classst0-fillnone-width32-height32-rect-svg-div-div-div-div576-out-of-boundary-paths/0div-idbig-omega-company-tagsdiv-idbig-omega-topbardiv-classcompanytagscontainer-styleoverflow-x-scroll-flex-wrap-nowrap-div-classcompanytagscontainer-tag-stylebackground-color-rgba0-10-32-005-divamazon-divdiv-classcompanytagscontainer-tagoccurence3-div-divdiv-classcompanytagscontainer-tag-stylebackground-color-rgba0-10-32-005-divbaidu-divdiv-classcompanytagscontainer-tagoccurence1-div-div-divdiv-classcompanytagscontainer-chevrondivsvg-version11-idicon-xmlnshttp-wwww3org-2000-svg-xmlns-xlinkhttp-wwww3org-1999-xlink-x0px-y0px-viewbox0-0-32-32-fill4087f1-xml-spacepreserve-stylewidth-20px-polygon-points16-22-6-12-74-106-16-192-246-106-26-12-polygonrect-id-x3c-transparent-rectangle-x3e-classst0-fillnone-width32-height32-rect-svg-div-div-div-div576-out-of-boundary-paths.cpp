class Solution {
public:
int mod = 1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[startRow][startColumn] = 1;
        int cnt = 0;
        for(int moves = 1;moves<= maxMove;moves++){
            vector<vector<int>> temp(m,vector<int>(n,0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i == m-1) cnt = (cnt+dp[i][j])%mod;
                    if(j == n-1) cnt = (cnt+dp[i][j])%mod;
                    if(i == 0) cnt = (cnt+dp[i][j])%mod;
                    if(j == 0) cnt = (cnt+dp[i][j])%mod;
                    temp[i][j] = (
                        ((i>0?dp[i-1][j]:0) + (i<m-1?dp[i+1][j]:0))%mod + 
                        ((j>0?dp[i][j-1]:0) + (j<n-1?dp[i][j+1]:0))%mod
                    )%mod;
                }
            }
            dp = temp;
        }
        return cnt;
    }
};