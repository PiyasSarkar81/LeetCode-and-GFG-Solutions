class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int,int>> s;
        int n = mat.size();
        for(int i=0;i<n;i++){
            int nos = count(mat[i].begin(),mat[i].end(),1);
            s.insert({nos,i});
        }
        vector<int> ans;
        for(auto i : s){
            if(k==0) break;
            ans.push_back(i.second);
            --k;
        }
        return ans;

    }
};