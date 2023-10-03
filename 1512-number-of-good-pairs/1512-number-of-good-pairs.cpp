class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans = 0;
        for(auto num : nums){
            if(mp.find(num)!=mp.end())ans += mp[num];
            mp[num]++;
        }
        return ans;
    }
};