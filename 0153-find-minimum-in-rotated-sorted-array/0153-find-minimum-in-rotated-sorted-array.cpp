class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int l = 0, r = n-1;
        if(nums[l] < nums[r]) return nums[l];
        while(l<r){
            int m = l + (r-l)/2;
            if(nums[m]<nums[r]){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        return nums[l];

    }
};