class Solution {
public:
    int maxScore(string s) {
        int left = 0, right = 0, n = s.size();
        if(s[0] == '0')left++;
        if(s[n-1] == '1') right++;
        int ans = INT_MIN;
        for(int i=1;i<=n-2;i++){
            if(s[i] == '1') right++;
        }
        ans = max(ans, left+right);
        for(int i=1;i<=n-2;i++){
            if(s[i] == '0') left++;
            else right--;
            ans = max(ans, left+right);
        }
        return ans;
    }
};