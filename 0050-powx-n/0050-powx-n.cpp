class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        if(n<0) x = 1/x;
        long num = labs(n);
        while(num){
            if(num & 1) ans *= x;
            x *= x;
            num >>= 1;
        }
        return ans;
    }
};