class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int> ans;
        int n = nums.size();
        for(auto num : nums) {
            mp[num]++;
        }
        for(auto m : mp) {
            if(m.second > n/3)
            ans.push_back(m.first);
        }
        return ans;
    }
};