class Solution {
public:
    int solve(const string& s, long k, int i, vector<int>& dp) {
        if (i==s.size()) return 1; 
        if (s[i]=='0') return 0; 
        if (dp[i]!=-1) return dp[i];
        int ans = 0;
        long num = 0;
        for (int j=i; j<s.size(); j++) {
            num = num * 10 + s[j] - '0'; 
            if (num>k) break; 
            ans += solve(s, k, j + 1, dp);
            ans %= 1000000007;
        }
        return dp[i] = ans;
    }
    
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, k, 0, dp);
    }
};