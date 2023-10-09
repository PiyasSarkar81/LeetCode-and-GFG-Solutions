class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans1 = -1, ans2 = -1,m;
        while(l<=r){
             m = l + (r-l)/2;
            if(nums[m]== target){
                ans1 = m;
                r = m -1;
            }
            else if(nums[m]<target){
                l = m + 1;
            }
            else r = m - 1;
        }
        l = 0, r = nums.size() - 1;
        while(l<=r){
             m = l + (r-l)/2;
            if(nums[m]== target){
                ans2 = m;
                l = m +1;
            }
            else if(nums[m]<target){
                l = m + 1;
            }
            else r = m - 1;
        }
        return {ans1, ans2};
    }
};