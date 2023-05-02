class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt =0;
        for(auto n: nums){
            if(n==0) return 0;
            if(n<0) cnt++;
        }
        if(cnt%2==0) return 1;
        return -1;
    }
};