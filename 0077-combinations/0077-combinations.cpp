class Solution {
public:

    void getSubsets(int n, int k, int idx, vector<int>& v, vector<vector<int>>& ans){
        if(v.size() == k){
            ans.push_back(v);
            return;
        }
        
        for(int i = idx;i<=n;i++){
            v.push_back(i);
            getSubsets(n,k,i+1,v,ans);
            v.pop_back();
        }
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        getSubsets(n,k,1,v,ans);
        return ans;
    }
};