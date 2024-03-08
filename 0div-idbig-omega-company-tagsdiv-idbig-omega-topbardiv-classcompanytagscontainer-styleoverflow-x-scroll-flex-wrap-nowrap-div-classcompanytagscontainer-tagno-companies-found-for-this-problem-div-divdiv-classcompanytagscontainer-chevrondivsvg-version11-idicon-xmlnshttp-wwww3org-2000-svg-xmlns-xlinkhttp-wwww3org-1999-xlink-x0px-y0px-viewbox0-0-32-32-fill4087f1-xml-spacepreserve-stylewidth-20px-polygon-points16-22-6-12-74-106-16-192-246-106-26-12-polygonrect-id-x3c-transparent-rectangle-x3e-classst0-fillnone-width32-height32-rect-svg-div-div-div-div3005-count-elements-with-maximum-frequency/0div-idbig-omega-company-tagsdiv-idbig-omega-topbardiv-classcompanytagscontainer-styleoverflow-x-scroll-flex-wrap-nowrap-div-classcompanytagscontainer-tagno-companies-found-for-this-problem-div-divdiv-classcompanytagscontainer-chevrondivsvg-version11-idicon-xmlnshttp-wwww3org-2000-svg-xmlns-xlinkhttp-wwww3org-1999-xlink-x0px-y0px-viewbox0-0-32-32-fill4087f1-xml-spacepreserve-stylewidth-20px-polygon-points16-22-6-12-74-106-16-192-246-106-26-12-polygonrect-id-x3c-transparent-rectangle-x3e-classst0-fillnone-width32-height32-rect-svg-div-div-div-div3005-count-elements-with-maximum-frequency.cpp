class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto& num : nums){
            mp[num]++;
        }
        int maxi = 0;
        for(auto m: mp){
            maxi = max(maxi,m.second);
        }
        int ans = 0;
        for(auto m : mp){
            if(m.second == maxi) ans += m.second;
        }
        return ans;
    }
};