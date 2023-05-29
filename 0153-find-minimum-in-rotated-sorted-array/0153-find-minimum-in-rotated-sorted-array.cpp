class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]<nums[n-1] ) return nums[0];
        int l = 0,r=n-1;
        while(l<=r){
            if(l==r) return nums[l];
            int m = l + (r-l)/2;
            if(nums[m] <nums[m+1] && nums[m]<nums[m-1]) return nums[m];
            else if(nums[0]<=nums[m]){
                l = m+1;
            } else r = m;
        }
        return nums[0];
    }
};