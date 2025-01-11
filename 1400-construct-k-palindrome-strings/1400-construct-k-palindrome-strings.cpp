class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(n<k) return false;
        vector<int>v(26,0);
        for(auto c : s) v[c-'a']++;
        int odd = 0;
        for(int i=0;i<26;i++) {
            if(v[i]%2) odd++;
        }
        return odd <= k;
    }
};