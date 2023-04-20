class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(),nums.end());
        int h = *max_element(nums.begin(),nums.end());
        
        if((h-l)<=2*k) return 0;
        return ((h-l)-2*k);
    }
};