class Solution {
public:
    int mod = 1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,0);
        dp[0] = 1;
        for(int end = 0; end <= high;end++ ) {
            if(end>=zero)dp[end] += dp[end-zero];
            if(end>=one)dp[end] += dp[end-one];
            dp[end] %= mod;
        }

        int ans = 0;
        for(int i=low;i<=high;i++) ans =  (ans+dp[i])%mod;

        return ans;
    }
};