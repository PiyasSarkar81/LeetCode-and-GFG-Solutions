class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int> firstOccurence(26,-1), lastOccurence(26,-1);
        unordered_set<string> st;

        for(int i=0;i<n;i++){
            if(firstOccurence[s[i]-'a'] == -1){
                firstOccurence[s[i]-'a'] = i;
            }
            lastOccurence[s[i]-'a'] = i;
        }

        for(int i=0;i<26;i++){
            if(firstOccurence[i] != -1 && lastOccurence[i] != -1 && firstOccurence[i] < lastOccurence[i]){
                unordered_set<char> middleChar;
                for(int j = firstOccurence[i]+1;j<lastOccurence[i];j++){
                    middleChar.insert(s[j]);
                }
                for(char c : middleChar){
                    st.insert(string(1,'a'+i) + c + string(1,'a'+i));
                }
            }
        }

        return st.size();
    }
};