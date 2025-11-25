class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> mp;
        int l =0, n = s.size(), ans = 0;
        for(int r = 0;r<n;r++){
            if(mp[s[r]] == false){
                mp[s[r]] = true;
            }
            else{
                while(l<r){
                    mp[s[l]] = false;
                    if(mp[s[l]] == mp[s[r]]){
                        mp[s[r]] = true;
                        l++;
                        break;
                    }
                    l++;
                }
            }
            ans = max(r-l+1, ans);
        }
        return ans;
    }
};