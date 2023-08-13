class Solution {
public:
    bool sol(int idx, vector<int>& nums, vector<int>& dp){
        if(idx == nums.size()) return true;
        if(dp[idx] != -1) return dp[idx];

        if(idx + 1 < nums.size() && nums[idx] == nums[idx+1]){
            if(sol(idx+2,nums,dp)) return true;
            if(idx+2 < nums.size() && nums[idx] == nums[idx+2]){
                if(sol( idx+3, nums, dp)) return true;
            }
        }
        if(idx+2 < nums.size() && nums[idx] == nums[idx+1]-1 && nums[idx] == nums[idx+2] - 2){
            if(sol(idx+3,nums,dp)) return true;
        }
        return dp[idx] = false;
    }
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return sol(0,nums,dp);
    }
};