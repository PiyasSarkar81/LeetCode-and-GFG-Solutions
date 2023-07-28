class Solution {
public:

    bool checkScore(int ans,int total){
        return ans>=total-ans;
    }
    int maxScore(vector<int>&v, int total, int i,int j,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        dp[i][j] = total - min(maxScore(v,total-v[i],i+1,j,dp),maxScore(v,total-v[j],i,j-1,dp));
        return dp[i][j];
    }
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(21,vector<int>(21,-1));
        int total =0;
        for(auto num : nums){
            total += num;
        }
        return checkScore(maxScore(nums,total,0,nums.size()-1,dp),total);
        
    }
};