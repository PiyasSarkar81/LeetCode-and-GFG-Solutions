class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n==0){
            return ans;
        }
        int i=0;
        while(i<n){
            int start = i;
            int end = i;
            while(end+1<n && nums[end+1]==nums[end]+1){
                end++;
            }
            if(start==end){
                ans.push_back(to_string(nums[start]));
            }
            else{
                ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            }
            i = end+1;
        }
        return ans;
    }
};