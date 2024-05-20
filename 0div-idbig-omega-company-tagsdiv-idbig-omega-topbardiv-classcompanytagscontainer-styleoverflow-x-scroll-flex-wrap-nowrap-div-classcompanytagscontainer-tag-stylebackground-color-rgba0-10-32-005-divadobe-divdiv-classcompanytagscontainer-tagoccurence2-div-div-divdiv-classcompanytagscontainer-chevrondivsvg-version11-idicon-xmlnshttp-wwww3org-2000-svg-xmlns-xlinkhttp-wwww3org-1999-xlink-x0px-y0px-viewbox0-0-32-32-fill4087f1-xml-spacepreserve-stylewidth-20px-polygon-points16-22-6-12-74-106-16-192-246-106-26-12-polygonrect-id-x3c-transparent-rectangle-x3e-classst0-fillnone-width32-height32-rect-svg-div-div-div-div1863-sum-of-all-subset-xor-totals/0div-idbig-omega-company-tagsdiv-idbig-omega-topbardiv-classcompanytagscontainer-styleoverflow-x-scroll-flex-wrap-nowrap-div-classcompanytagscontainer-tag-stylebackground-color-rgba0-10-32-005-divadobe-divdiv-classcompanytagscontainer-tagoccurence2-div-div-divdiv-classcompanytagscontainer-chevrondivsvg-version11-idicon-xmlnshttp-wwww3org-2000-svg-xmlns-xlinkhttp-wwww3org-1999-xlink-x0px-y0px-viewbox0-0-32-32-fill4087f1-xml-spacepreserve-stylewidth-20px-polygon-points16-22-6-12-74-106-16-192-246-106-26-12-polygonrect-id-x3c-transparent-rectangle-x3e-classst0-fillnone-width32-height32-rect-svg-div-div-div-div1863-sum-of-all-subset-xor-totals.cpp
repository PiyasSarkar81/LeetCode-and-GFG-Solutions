class Solution {
public:
    int xorSum(vector<int>& nums,int pos, int curr){
        if(pos == nums.size()){
            return curr;
        }
        int include = xorSum(nums, pos+1, curr);
        int exclude = xorSum(nums, pos+1, curr ^ nums[pos]);
        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return xorSum(nums, 0, 0);
    }
};