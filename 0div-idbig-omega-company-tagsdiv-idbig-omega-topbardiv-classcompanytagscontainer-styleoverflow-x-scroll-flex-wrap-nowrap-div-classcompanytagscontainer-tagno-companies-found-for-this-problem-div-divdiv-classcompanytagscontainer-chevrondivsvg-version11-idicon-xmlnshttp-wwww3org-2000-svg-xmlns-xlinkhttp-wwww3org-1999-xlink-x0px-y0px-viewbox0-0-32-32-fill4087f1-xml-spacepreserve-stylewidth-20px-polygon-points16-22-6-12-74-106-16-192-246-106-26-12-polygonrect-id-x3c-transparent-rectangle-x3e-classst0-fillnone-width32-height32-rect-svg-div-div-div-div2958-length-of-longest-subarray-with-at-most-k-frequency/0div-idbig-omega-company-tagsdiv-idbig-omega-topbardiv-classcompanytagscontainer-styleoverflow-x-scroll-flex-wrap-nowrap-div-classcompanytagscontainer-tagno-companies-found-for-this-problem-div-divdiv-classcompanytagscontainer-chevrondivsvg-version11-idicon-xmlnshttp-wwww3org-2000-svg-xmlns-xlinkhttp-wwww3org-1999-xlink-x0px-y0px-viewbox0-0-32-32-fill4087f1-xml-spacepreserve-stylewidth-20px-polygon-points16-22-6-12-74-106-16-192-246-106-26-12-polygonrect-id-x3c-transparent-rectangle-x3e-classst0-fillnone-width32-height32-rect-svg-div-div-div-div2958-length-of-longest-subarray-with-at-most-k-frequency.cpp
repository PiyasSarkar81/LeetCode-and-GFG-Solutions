class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j =0, n = nums.size(), ans =0;
        unordered_map<int,int> mp;
        
        while(j < n){
            mp[nums[j]]++;
            if(mp[nums[j]] > k){
                while(i < j and mp[nums[j]] > k){
                    if(mp[nums[i]] == 1)
                        mp.erase(nums[i]);
                    else
                        mp[nums[i]]--;
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
        
    }
};