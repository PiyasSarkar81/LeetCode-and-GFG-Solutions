class Solution {
public:
    bool isPalindrome(string s) {
        string g = "";
        for(auto c : s) {
            if(!isalnum(c)) continue;
            g += tolower(c);
        }
        int l = 0, r = g.size()-1;
        while(l<r){
            if(g[l++] != g[r--]) return false;
        }
        return true;
    }
};