class Solution {
public:
    bool isPalindrom(string& s,int i,int j){
        while(i<j){
            if(s[i++] != s[j--]) return false; 
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size(),size = 0;
        string ans;
        for(int i=0;i<n;i++){
            for(int j = i;j<n;j++){
                if(isPalindrom(s,i,j) && (j-i+1) > size) {
                    size = j-i+1;
                    ans = s.substr(i,size);
                }
            }
        }
        return ans;
    }
};