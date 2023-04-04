class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> ch;
        int cnt =1;
        for(int i =0;i<s.size();i++){
            if(ch.find(s[i])!=ch.end()){
                ch.clear();
                cnt++;
            }
            ch.insert(s[i]);
        }
        return cnt;
    }
};