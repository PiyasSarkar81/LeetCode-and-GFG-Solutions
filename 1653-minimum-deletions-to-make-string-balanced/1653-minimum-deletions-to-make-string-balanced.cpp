class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp(n+1);
        int bcnt =0;
        for(int i =0;i<n;i++){
            if(s[i]=='a'){
                dp[i+1] = min(dp[i]+1,bcnt);
            }
            else{
                dp[i+1] = dp[i];
                bcnt++;
            }
        }
        return dp[n];
    }
};