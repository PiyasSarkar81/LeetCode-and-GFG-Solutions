class Solution {
public:
   
    int minSubArrayLen(int target, vector<int>& nums) {
        int len =INT_MAX,l=0,r=0, sum =0;
        while(r<nums.size()){
            sum += nums[r++];
            while(sum>=target){
                len = min(len,r-l);
                sum -= nums[l++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};