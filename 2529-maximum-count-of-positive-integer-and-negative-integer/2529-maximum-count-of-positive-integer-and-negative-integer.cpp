class Solution {
public:
    int binarySearch(vector<int>& nums,int target){
        int l =0,r=nums.size()-1,ans = nums.size();
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m]<target){
                l = m+1;
            }
            else{
                ans = m;
                r = m-1;
            }
        }
        return ans;
    }
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = binarySearch(nums,0);
        int pos = nums.size()-binarySearch(nums,1);
        return max(neg, pos);
    }
};