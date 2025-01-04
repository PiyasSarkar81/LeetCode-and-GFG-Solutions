class Solution {
public:
    long long mod = 1e18+31;
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+1,0);
        dp[0] = 1;

        for(int t=1;t<=target;t++){
            for(auto num : nums){
                if(num <= t)
                    dp[t] = (dp[t]+ dp[t-num])%mod;
            }
        }

        return dp[target];
        
    }
};