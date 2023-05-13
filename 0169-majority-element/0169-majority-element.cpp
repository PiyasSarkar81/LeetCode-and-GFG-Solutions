class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int ct =0;
        // int ele =0;
        // for( int num : nums){
        //     if(ct == 0) ele = num;
        //     if(ele == num ) ct++;
        //     else ct--;
        // }
        // return ele;
        
        // Moore's voting algorithom (better solution)
        
        int ele,cnt =0;
        int n = nums.size();
        for(int i =0; i < n; i++) {
            if(cnt == 0) {
                cnt++;
                ele = nums[i];
            } 
            else if( nums[i] == ele ) {
                cnt++;
            } else cnt--;
        }
        
        int c =0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == ele) c++;
        }
        if(c > n / 2) return ele;
        return -1;
    }
};