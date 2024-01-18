class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int prev = 1, prev2 = 2, ans;
        for(int i = 3;i<= n;i++){
            ans = prev + prev2;
            prev = prev2;
            prev2 = ans;
        }
        return ans;
        
    }
};