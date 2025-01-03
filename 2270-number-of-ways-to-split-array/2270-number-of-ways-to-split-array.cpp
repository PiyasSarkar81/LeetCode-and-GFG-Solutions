class Solution {
public:

    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        long long left = nums[0], right = 0;
        for(int i=1;i<n;i++) right += nums[i];
        if(left >= right) ans++;
        for(int i=1;i<n-1;i++){
            left += nums[i];
            right -= nums[i];
            if(left >= right) ans++;
        }
        return ans;
    }
};