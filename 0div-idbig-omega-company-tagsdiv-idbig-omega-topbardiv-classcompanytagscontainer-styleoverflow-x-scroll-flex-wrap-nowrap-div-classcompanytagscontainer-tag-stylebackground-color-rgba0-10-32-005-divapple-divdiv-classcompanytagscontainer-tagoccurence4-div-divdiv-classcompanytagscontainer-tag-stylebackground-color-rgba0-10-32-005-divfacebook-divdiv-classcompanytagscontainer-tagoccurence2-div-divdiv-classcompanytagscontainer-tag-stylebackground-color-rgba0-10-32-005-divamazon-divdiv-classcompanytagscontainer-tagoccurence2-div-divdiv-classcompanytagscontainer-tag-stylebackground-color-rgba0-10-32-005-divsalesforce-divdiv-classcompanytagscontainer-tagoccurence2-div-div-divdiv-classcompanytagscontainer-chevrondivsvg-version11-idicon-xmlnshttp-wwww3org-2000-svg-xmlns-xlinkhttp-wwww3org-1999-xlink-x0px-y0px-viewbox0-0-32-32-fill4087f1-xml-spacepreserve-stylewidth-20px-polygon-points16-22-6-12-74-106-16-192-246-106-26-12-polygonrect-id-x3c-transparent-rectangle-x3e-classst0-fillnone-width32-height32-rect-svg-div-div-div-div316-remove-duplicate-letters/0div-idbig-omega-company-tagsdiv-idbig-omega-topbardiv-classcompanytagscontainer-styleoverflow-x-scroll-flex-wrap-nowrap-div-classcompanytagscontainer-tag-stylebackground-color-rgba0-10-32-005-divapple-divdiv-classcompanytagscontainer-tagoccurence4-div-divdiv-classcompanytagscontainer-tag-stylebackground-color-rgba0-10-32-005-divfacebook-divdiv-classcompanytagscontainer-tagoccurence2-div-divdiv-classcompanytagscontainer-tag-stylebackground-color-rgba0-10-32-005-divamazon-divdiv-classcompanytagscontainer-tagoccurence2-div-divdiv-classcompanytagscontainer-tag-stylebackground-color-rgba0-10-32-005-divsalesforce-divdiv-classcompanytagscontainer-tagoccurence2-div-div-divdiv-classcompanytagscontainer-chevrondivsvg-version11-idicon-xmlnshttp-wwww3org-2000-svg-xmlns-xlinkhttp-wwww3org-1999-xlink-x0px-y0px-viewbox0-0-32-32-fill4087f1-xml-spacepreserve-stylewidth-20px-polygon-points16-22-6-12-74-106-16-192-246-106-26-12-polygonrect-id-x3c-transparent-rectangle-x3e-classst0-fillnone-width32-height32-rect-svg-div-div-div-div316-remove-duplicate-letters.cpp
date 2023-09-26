class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26,0), vis(26,0);
        string ans = "";
        int n = s.size();
        for(int i=0;i<n;i++) cnt[s[i]-'a']++;
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']--;
            if(!vis[s[i]-'a']){
                while(ans.size()>0 && ans.back()>s[i] && cnt[ans.back()-'a']>0){
                    vis[ans.back()-'a'] = 0;
                    ans.pop_back();
                }
                ans += s[i];
                vis[ans.back() - 'a'] = 1;
            }

        } 
        return ans;
    }
};