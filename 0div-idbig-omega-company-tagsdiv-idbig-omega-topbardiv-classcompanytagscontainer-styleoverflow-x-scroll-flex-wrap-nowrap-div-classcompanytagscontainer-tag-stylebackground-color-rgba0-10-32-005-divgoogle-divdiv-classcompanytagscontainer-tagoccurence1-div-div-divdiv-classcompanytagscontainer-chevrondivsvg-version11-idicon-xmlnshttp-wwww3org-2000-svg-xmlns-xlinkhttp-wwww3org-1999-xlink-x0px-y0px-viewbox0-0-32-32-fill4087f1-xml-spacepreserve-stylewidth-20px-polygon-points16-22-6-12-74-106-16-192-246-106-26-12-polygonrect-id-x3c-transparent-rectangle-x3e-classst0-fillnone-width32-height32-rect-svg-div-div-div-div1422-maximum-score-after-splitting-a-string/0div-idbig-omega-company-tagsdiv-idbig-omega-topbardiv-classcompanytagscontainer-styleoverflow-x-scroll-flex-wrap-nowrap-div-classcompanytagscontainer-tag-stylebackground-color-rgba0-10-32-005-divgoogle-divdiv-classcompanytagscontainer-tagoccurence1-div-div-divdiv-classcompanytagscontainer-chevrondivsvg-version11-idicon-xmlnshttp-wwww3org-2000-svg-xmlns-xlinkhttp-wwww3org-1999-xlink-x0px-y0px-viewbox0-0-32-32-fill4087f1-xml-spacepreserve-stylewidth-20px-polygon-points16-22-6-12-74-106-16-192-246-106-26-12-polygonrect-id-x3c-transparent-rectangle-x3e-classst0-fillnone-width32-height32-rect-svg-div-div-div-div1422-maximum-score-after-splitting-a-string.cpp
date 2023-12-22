class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), ones = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '1') ones++;
        }
        vector<int> ans(n-1);
        int zeros = 0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0') zeros++;
            if(s[i] =='1') ones--;
            ans[i] = zeros+ones;
        }
        return *max_element(ans.begin(), ans.end());
    }
};