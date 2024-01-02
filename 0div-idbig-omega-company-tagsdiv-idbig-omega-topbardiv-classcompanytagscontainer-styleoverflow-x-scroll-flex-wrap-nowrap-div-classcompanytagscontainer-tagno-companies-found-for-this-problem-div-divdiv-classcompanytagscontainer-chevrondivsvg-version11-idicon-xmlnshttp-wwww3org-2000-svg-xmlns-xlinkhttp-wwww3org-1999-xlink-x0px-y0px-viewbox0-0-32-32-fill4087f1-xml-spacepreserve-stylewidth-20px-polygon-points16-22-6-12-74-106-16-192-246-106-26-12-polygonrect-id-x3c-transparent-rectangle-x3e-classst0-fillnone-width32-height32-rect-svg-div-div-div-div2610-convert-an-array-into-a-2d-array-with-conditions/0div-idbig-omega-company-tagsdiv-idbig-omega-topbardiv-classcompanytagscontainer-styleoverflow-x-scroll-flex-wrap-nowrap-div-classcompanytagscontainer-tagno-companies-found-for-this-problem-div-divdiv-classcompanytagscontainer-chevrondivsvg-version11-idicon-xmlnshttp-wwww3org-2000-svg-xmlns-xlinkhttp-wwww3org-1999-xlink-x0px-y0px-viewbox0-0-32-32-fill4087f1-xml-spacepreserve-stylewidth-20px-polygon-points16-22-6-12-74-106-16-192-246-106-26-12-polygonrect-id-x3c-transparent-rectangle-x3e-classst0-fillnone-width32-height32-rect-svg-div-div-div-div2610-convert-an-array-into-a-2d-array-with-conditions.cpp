class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto& i : nums){
            m[i]++;
        }
        vector<vector<int>> ans;
        while(!m.empty()){
            vector<int> v;
            vector<int> del;
            for(auto& i : m){
                v.push_back(i.first);
                m[i.first]--;
                if(m[i.first]==0){
                    del.push_back(i.first);
                }
            }
            ans.push_back(v);
            for(auto& i : del){
                m.erase(i);
            }
        }
        return ans;
    }
};