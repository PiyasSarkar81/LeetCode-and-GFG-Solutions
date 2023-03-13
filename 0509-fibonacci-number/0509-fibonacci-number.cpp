class Solution {
public:
    int fib(int n) {
        if(n<2) return n;
        int prev = 1, prev2 = 0, ans;
        for(int i = 1;i<n;i++){
            ans = prev + prev2;
            prev2 = prev;
            prev = ans;
        }
        return ans;
    }
};