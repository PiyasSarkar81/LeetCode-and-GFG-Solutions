class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, l = 0, n = s.size();
        unordered_map<char,int> mp;
        
        int maxf = 0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);
            while((r-l+1)-maxf > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, (r-l+1));
        }
        
        return ans;
    }
};