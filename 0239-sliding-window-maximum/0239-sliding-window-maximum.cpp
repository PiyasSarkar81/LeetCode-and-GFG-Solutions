class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int l =0;
        vector<int> ans(n-k+1);
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++) mp[nums[i]]++;

        ans[0] = *max_element(nums.begin(), nums.begin()+k);
        while(l+k<n){
            mp[nums[l]]--;
            if(mp[nums[l]] == 0) mp.erase(nums[l]);
            mp[nums[l+k]]++;
            if(nums[l] == ans[l]) {
                int val= INT_MIN;
                for(auto m : mp) val = max(val,m.first);
                ans[l+1] = val;
            }
            else ans[l+1] = max(ans[l], nums[l+k]);
            l++;

        }
        return ans;

    }
};