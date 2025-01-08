class Solution {
public:
    bool isPrefixAndSuffix(string& str1, string& str2) {
        return str2.substr(0, str1.length()) == str1 && 
               str2.substr(str2.length() - str1.length()) == str1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++)
                if(isPrefixAndSuffix(words[i],words[j])) ans++;
        }
        return ans;
    }
    
};