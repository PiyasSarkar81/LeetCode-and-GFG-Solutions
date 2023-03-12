class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ct =0;
        int ele =0;
        for( int num : nums){
            if(ct == 0) ele = num;
            if(ele == num ) ct++;
            else ct--;
        }
        return ele;
    }
};