class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size(), ans = 0;
        for(auto& word : words){
            if(word.substr(0,n) == pref) ans++;
        }
        return ans;
    }
};