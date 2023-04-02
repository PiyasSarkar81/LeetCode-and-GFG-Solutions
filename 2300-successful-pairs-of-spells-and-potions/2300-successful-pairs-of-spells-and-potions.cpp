class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(auto s : spells){
            long need = (success + s -1)/s;
            auto it = lower_bound(potions.begin(),potions.end(),need);
            ans.push_back(potions.end()-it);
        }
        return ans;
    }
};