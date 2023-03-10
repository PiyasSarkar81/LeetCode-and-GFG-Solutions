class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1,m;
        if(target > nums[r]) return r+1;
        if(target < nums[l]) return 0;
        while(l<=r){
             m = l + (r-l)/2;
            if(nums[m]== target )return m;
            else if(nums[m]<target) l = m+1;
            else r = m-1;
        }
        return l;
    }
};