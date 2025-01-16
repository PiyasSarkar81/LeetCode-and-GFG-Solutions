class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        for(auto n : nums1) xor1 ^= n;
        for(auto n : nums2) xor2 ^= n;
        int lenNum1 = nums1.size(), lenNum2 = nums2.size();
        int ans = ((lenNum2 % 2) ? xor1 : 0)  ^ ((lenNum1 % 2) ? xor2 : 0);
        return ans;
        
    }
};