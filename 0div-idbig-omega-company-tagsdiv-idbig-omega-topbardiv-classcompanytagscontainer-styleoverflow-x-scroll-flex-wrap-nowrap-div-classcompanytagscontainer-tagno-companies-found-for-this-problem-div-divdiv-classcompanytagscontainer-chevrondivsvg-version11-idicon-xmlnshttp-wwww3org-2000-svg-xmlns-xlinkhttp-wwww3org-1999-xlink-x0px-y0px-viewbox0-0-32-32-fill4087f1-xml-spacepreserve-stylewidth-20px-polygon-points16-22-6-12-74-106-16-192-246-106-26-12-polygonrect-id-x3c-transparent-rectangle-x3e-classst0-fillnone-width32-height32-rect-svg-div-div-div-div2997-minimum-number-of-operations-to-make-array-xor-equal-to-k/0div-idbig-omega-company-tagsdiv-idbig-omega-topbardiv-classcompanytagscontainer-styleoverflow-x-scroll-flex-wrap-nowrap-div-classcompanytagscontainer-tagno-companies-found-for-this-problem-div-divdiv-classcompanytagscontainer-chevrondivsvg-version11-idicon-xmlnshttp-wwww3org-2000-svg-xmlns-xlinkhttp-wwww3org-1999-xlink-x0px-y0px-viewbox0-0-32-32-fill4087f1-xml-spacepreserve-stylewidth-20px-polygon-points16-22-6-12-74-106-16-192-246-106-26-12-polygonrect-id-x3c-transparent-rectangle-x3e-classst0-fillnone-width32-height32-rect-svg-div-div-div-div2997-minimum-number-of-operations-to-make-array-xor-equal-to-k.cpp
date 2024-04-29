class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int op =0;
        for(auto &num : nums) op ^= num;
        op = op^k;
        int ans = 0;
        while(op != 0){
            ans += op&1;
            op >>= 1;
        }
        return ans;
    }
};