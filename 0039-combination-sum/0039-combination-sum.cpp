class Solution {
public:
   void solve(vector<int>& candidates,int target,int idx,vector<int>& curr,int total,vector<vector<int>>& ans){
        if(total == target){
            ans.push_back(curr);
            return;
        }
        if(total > target || idx >= candidates.size()) return;

        curr.push_back(candidates[idx]);
        solve(candidates, target, idx, curr, total + candidates[idx], ans);
        curr.pop_back();
        solve(candidates, target, idx+1, curr, total, ans);

   } 

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> curr;
        solve(candidates,target,0,curr,0,ans);
        return ans;
    }
};