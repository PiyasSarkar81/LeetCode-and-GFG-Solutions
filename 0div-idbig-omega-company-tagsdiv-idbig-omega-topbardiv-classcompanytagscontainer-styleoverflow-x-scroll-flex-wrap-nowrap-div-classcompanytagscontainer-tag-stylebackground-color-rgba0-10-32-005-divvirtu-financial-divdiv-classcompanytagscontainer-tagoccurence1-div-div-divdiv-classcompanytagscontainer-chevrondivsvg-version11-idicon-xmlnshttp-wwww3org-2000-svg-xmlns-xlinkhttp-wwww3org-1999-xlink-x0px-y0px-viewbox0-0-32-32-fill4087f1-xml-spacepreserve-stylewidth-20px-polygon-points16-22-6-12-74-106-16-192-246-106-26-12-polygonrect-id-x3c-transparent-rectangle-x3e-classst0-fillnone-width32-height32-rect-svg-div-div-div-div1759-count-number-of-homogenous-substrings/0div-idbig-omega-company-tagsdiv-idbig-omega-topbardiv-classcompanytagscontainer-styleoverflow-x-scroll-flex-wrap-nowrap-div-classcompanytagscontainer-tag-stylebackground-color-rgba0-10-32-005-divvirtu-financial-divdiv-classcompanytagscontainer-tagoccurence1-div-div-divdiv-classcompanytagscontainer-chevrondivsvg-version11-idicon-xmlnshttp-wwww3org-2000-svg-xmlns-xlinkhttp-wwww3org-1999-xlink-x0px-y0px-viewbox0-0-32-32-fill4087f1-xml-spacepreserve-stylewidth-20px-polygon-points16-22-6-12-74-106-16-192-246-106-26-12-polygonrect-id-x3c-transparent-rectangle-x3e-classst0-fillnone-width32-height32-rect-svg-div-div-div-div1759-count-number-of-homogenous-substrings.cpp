class Solution {
public:
    int mod = 1e9+7;
    int countHomogenous(string s) {
        int ans = 0, n = s.size(), cnt =0;
        for(int i=0;i<n;i++){
            if(i==0 || s[i] == s[i-1]) cnt++;
            else cnt = 1;
            ans = (ans + cnt)%mod;
        }
        return ans;
    }
};