class Solution {
public:
    int solve(vector<vector<int>>& events,vector<vector<int>>&dp, int idx, int limit, int k){
        if(idx == events.size()) return 0;
        if(k==0) return 0;
        if(events[idx][0]<= limit) return  solve(events, dp, idx+1,limit,k);
        if(dp[idx][k]!=-1) return dp[idx][k];
        int res = max(events[idx][2]+solve(events,dp,idx+1,events[idx][1],k-1), solve(events,dp,idx+1,limit,k));
        return dp[idx][k] = res;
    }
  
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n = events.size();
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(events, dp, 0, 0,k);

    }
};