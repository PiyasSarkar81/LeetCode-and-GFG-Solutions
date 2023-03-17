class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]==0) return -1;
        
        int ladder = nums[0];
        int stairs = nums[0];
        int jump = 1;
        
        for(int i = 1; i<n;i++){
            if(i==n-1) return jump;
            
            if(i + nums[i] > ladder)
                ladder = i + nums[i];
            
            stairs--;
            
            if(stairs==0){
                jump++;
                if(i>=ladder) return -1;
                stairs = ladder - i;
            }
        }
        return -1;
    }
};