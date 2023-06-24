class Solution {
public:
    unordered_map<int,int>dp[21];
    int solve(int idx,int diff,vector<int>&rods){
        if(idx==rods.size()){
            if(diff==0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[idx].count(diff)){
            return dp[idx][diff];
        }
        //not pick
        int x=solve(idx+1,diff,rods);
        //pick and put it in first support
        int y=rods[idx]+solve(idx+1,diff+rods[idx],rods);
        //pick and put it in second support
        int z=rods[idx]+solve(idx+1,diff-rods[idx],rods);
        //take maximum of all
        return dp[idx][diff]=max({x,y,z});
    }
    int tallestBillboard(vector<int>& rods) {
       int n=rods.size();
       //divide by 2 bcz rods[idx] is added 2 times
        return solve(0,0,rods)/2;
    }
};