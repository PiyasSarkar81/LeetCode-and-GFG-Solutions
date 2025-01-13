class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> mp;
        for(auto& c : s) mp[c]++;
        int delEle = 0;
        for(auto& m: mp){
            if(m.second % 2 == 1) delEle += m.second -1;
            else delEle += m.second - 2; 
        }
        return s.size() - delEle;
    }
};