class Solution {
public:

    int minTaps(int n, vector<int>& ranges) {
        const int INF = 1e9+7;
        vector<int> dp(n+1,INF);
        dp[0]=0;
        for(int i=0;i<=n;i++){
            int start_tap = max(0,i-ranges[i]);
            int end_tap = min(n,i+ranges[i]);
            for(int j = start_tap; j<=end_tap;j++){
                dp[end_tap] = min(dp[end_tap], dp[j]+1);
            }
        }
        if(dp[n]==INF) return -1;
        return dp[n];
    }
};