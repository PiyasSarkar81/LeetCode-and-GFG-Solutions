class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), j =0, i =0;
        long long ans = 0, cnt = 0;
        int maxi = *max_element(nums.begin(), nums.end());
        while(j < n){
            if(nums[j] == maxi) cnt++;
            while(cnt >= k){
                ans += n  - j;
                if(nums[i] == maxi) cnt--;
                i++;
            }
            j++;
        }
        
        return ans;
    }
};