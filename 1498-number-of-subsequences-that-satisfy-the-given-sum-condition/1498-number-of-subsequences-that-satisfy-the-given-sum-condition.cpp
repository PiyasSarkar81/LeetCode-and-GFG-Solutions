class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        vector<int> exp(nums.size(),1);
        for(int i = 1; i< nums.size(); i++){
            exp[i] = (2 * exp[i - 1]) % MOD;
        }
        
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, count = 0;
        while(left <= right){
            if(nums[left] + nums[right] > target) right--;
            else{
                count = (count + exp[right - left]) % MOD;
                left++;
            }
        }
        return count;
    }
};