class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        for(auto n : nums1) nums.push_back(n);
        for(auto n : nums2) nums.push_back(n);
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n%2){
            return (double)nums[n/2];
        }
        else{
            double ans = nums[n/2] + nums[n/2-1];
            return ans/2;

        }
        return -1;
    }
};