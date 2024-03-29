class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        int len = 0,start =0;
        for(int i =0;i<s.length();i++){
            int len1 = expandFromCenter(s,i,i);
            int len2 = expandFromCenter(s,i,i+1);
            if(len < max(len1,len2)){
                len = max(len1,len2);
                start = i - (len - 1)/2;
            }
        }
        return s.substr(start,len);
    }
    int expandFromCenter(string s,int left, int right){
        while(left>right || s.length()<1) return 0;
        while(0<=left && right<s.length() && s[left] == s[right]) left--,right++;
        return right - left -1;
    }
};