class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        unordered_map<char,int> um; 
        for(auto c : s){
            um[c]++;
            if(um[c]%2 == 1) oddCount++;
            else oddCount--;
        } 
        if(oddCount>1) return s.size() - oddCount+1;
        return  s.size();
    }
};