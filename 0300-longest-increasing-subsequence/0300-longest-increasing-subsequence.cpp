class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub(n,1);
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[j]<nums[i] && sub[i]<=sub[j])
                    sub[i] = 1 + sub[j];
            }
        }
        int maxi = 1;
        for(int i =0;i<n;i++){
            if(sub[i]>maxi) maxi = sub[i];
        }
        return maxi;
    }
};