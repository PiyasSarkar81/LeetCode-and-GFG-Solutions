class Solution {
public:
    unordered_map<int, int> lookup;
    int dp(int a, int mask, vector<int>& nums, int n) {
        if(mask == 0) return 0;
        int key = a + 10 * mask;
        if(lookup.find(key) != lookup.end())
            return lookup[key];
        
        int maxEle = 0;
        for(int i =0;i<n;i++) {
            if(mask & (1<<i)) {
                for(int j = i+1; j<n;j++) {
                    if(mask & (1<<j)) {
                        maxEle = max(maxEle,a* __gcd(nums[i], nums[j]) + dp(a+1, mask^(1<<i)^(1<<j), nums, n));
                    }
                }
            }
        }
        return lookup[key] = maxEle;
    }
    
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        return dp(1, (1<<n) - 1, nums, n);
    }
};