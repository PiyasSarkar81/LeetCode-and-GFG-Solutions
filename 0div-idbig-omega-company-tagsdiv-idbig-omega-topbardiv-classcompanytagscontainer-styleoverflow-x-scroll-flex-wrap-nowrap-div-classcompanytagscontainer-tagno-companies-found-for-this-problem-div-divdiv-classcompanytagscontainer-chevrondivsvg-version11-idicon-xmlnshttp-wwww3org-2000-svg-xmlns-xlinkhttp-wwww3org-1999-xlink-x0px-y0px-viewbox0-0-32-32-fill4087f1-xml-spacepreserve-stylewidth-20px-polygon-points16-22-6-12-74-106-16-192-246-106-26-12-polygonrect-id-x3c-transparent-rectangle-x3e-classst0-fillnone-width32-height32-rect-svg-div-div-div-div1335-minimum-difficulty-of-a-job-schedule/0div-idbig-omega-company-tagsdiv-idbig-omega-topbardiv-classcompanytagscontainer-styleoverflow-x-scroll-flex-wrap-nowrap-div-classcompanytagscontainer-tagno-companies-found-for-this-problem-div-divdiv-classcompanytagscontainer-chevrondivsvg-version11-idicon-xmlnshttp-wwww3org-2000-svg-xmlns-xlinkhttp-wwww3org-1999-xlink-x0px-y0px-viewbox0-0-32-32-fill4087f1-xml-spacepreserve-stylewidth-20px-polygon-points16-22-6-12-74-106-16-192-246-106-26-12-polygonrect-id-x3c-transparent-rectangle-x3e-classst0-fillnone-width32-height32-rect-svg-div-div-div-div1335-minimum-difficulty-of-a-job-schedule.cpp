class Solution {
public:
    int solve(vector<vector<int>>& dp,vector<int>& mat, int n,int idx,int d){
        if(d==1) return *max_element(mat.begin()+idx,mat.end());
        if(dp[idx][d] != -1) return dp[idx][d];
        int maxi = INT_MIN, ans = INT_MAX;
        for(int i=idx;i<=n-d;i++){
            maxi = max(maxi, mat[i]);
            ans = min(ans,maxi+solve(dp,mat,n,i+1,d-1)); 
        }
        return dp[idx][d] = ans;
    }


    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int>> dp(301,vector<int>(11,-1));
        return solve(dp,jobDifficulty,n,0,d);
    }
};