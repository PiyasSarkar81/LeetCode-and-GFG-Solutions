class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        for(auto c : s) mp[c]++;
        for(auto c : t){
            if(mp.find(c) == mp.end()) return false;
            mp[c]--;
        }
        for(auto m : mp) if(m.second != 0) return false;
        return true;
    }
};