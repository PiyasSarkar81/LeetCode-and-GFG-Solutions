class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
        
        long long cnt = 0;
        int l = 0;
        for(int r=0; r<n; r++) {
            while(l <= r) {
                long long sum = (l > 0) ? (prefix[r] - prefix[l-1]) : prefix[r];
                if(sum * (r-l+1) < k) {
                    break;
                }
                l++;
            }
            cnt += (r - l + 1);
        }
        
        return cnt;
    }
};