class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9+7;
        vector<long>count(n+1);
        count[1]=1;
        for(int i=2;i<=n;i++){
            int r = 2*i-1;
            count[i] = ((i*r)%mod*count[i-1]%mod)%mod;
        }
        return count[n];
    }
};