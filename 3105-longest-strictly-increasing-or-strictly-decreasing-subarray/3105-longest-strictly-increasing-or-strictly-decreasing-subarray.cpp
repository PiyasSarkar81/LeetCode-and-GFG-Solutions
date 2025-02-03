class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1, n = nums.size(), incCnt=1, decCnt=1;
        if(n==0) return 0;
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                incCnt++;
                decCnt = 1;
            }
            else if(nums[i] < nums[i-1]){
                decCnt++;
                incCnt = 1;
            }
            else {
                incCnt = 1;
                decCnt = 1;
            }
            if(incCnt > ans) ans = incCnt;
            if(decCnt > ans) ans = decCnt; 
        }
        return ans;
    }
};