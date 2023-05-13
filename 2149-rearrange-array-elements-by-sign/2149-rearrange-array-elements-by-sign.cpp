class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posInd = 0, negInd = 1;
        vector<int> ans(n);
        for(int i =0;i <n;i++) {
            if(nums[i] < 0) {
                ans[negInd] = nums[i];
                negInd += 2;
            } else {
                ans[posInd] = nums[i];
                posInd += 2;
            }
        }
        return ans;
    }
};