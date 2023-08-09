class Solution {
public:    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0, r = nums[n-1]-nums[0];
        while (l < r) {
            int mid = l + (r-l)/2;
            int count =0;
           for(int i =1;i<nums.size();i++){
               if(mid >= nums[i]-nums[i-1]) {
               count++;
               i++; 
               }
           }
           if(count>=p) {
               r = mid;
           }else{
               l = mid +1;
           }
        }
        return l;
    }
};