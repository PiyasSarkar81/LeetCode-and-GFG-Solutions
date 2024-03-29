class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l =0,r= n-1,m;
        while(l<r){
            m = l + (r-l)/2;
            if(m%2==1){
                m--;
            }
            if(nums[m]!=nums[m+1]){
                r = m;
            }
            else{
                l=m+2;
            }
        }
        return nums[l];
    }
};