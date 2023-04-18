class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = min(word1.size(),word2.size());
        string ans = "";
        for(int i=0;i<n;i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        if(word1.size()>n){
            for(int i=n;i<word1.size();i++){
            ans+=word1[i];
        }
        }
        if(word2.size()>n){
            for(int i=n;i<word2.size();i++){
            ans+=word2[i];
        }
        }
        return ans;
    }
};