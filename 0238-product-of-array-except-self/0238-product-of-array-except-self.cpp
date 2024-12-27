class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero = 0, n = nums.size();
        
        vector<int> ans(n,0);
        long long p = 1;
        for(auto num : nums){
            if(num == 0) zero++;
            else p *= num;
        }
        if(zero>1) return ans;

        for(int i=0;i<n;i++){
            if(!zero && nums[i] != 0) ans[i] = p/nums[i];
            else if(nums[i] == 0) ans[i] = p;
        }

        return ans;
    }
};