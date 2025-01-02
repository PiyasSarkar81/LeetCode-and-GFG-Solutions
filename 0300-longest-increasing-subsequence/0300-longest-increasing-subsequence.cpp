class Solution {
public:
    int solve(int idx,int pre_idx, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(idx == n) return 0;
        if(dp[idx][pre_idx+1] != -1) return dp[idx][pre_idx+1];

        int len = solve(idx+1, pre_idx, nums,n,dp);
        if(pre_idx == -1 || nums[pre_idx] < nums[idx]){ 
            len = max(len, 1 + solve(idx+1,idx,nums,n,dp));
        }

        return dp[idx][pre_idx+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,n,dp);
    }
};