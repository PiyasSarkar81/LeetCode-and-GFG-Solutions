class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0, diff = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1]) diff++;
            ans += diff;
        }
        return ans;
    }
};