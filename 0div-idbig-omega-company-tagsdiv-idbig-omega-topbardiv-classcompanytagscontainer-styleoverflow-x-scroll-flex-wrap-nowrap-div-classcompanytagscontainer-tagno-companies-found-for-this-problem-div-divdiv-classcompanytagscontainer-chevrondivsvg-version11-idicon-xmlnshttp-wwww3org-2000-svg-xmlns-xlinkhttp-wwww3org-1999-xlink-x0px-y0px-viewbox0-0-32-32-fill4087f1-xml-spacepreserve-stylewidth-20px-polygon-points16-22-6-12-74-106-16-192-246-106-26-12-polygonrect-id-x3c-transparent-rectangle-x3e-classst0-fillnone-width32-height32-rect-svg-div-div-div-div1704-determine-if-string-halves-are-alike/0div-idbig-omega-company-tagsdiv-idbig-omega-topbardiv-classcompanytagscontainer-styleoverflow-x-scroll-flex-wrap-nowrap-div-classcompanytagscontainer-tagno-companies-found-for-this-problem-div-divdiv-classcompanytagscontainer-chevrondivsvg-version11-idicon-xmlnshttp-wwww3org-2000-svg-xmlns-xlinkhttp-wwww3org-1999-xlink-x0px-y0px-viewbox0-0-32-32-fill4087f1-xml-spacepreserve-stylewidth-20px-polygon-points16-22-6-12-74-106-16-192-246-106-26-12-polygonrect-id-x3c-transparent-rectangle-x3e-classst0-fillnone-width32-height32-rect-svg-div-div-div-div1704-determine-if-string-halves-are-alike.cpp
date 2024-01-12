class Solution {
public:

    bool isVowel(char c){
        char l = (char)tolower(c);
        if(l == 'a' || l == 'e' || l=='i'||l=='o'||l=='u') return true;
        return false;
    }

    bool halvesAreAlike(string s) {
        int n = s.size(), cnt1=0,cnt2=0;
        for(int i=0;i<n/2;i++){
            if(isVowel(s[i])) cnt1++;
            if(isVowel(s[i+n/2])) cnt2++;
        }
        return cnt1==cnt2;
    }
};