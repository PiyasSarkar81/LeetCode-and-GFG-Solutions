class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), pre = 0, curr = 0;
        for(int i=0;i<n;i++){
            int temp = max(nums[i]+pre, curr);
            pre = curr;
            curr = temp;
        }
        return curr;
    }
};