class Solution {
public:
    int dfs(vector<vector<int>>& piles,vector<vector<int>>& dp, int p,int coins){
        if(p<0 || coins==0) return 0;
        if(dp[p][coins]!=-1) return dp[p][coins];
        int n = min((int)piles[p].size(),coins);
        dp[p][coins] = dfs(piles,dp,p-1,coins); // skiping current pile
        
        int currPile =0;
        for(int i=0;i<n;i++){
            currPile += piles[p][i];
            dp[p][coins] = max(dp[p][coins],currPile + dfs(piles, dp,p-1,coins-i-1));
        }
        return dp[p][coins];
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return dfs(piles,dp,n-1,k);
    }
};