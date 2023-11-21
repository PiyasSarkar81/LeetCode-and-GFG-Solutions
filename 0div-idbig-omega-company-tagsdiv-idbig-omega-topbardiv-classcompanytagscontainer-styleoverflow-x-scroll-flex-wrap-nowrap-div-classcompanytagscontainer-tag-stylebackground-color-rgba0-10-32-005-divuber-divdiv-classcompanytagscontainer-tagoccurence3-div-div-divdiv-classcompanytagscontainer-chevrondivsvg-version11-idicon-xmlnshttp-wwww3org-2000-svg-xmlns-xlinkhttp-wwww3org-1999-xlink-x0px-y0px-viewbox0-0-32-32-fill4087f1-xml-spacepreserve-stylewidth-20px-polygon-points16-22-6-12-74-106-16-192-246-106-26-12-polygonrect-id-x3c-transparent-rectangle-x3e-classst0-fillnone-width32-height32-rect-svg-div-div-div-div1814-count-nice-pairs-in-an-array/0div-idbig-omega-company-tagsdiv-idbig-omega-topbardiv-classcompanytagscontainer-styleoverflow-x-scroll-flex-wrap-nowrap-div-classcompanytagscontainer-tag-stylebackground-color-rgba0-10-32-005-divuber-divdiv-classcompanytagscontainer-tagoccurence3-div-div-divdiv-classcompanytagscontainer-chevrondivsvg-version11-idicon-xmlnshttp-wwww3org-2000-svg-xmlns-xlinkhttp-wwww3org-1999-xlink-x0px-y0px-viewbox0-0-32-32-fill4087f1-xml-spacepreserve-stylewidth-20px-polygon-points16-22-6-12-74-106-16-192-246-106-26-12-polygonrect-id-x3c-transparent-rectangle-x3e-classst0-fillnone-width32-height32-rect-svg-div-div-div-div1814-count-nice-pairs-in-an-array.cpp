class Solution {
public:
    int mod = 1e9+7;
    int rev(int num){
        int revnum =0;
        while(num>0){
            revnum = revnum*10 + num%10;
            num /= 10;
        }
        return revnum;
    }
    int countNicePairs(vector<int>& nums) {
        int ans =0, n = nums.size();
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - rev(nums[i]);
            ans = (ans + freq[diff]) % mod;
            freq[diff]++;
        }
        return ans;
    }
};