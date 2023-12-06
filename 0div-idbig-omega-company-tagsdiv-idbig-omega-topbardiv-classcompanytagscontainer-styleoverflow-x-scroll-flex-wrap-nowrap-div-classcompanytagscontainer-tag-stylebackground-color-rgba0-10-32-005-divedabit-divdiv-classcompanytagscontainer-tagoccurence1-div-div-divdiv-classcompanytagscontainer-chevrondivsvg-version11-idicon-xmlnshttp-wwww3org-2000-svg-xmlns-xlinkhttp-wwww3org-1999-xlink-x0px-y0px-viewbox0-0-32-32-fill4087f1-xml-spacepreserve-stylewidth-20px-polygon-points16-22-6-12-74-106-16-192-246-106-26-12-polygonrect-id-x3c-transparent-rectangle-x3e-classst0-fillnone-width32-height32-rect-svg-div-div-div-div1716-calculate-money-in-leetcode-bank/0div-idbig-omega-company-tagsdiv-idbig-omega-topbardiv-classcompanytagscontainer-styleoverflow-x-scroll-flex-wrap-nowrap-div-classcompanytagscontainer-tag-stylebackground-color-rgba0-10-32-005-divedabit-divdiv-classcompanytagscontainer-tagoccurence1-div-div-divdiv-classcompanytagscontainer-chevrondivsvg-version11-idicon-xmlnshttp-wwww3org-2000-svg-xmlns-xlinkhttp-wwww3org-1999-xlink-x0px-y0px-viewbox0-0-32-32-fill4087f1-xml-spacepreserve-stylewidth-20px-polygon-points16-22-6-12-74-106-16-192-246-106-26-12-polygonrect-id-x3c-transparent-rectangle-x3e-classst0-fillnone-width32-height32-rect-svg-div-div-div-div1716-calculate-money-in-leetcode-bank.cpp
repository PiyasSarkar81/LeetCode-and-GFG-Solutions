class Solution {
public:
    int totalMoney(int n) {
        int m = n/7, ans = 0;
        for(int i =1;i<=m;i++)
            ans += 7*(i+3);
        for(int i=7*m;i<n;i++)
            ans += ++m;
        return ans;
    }   
};