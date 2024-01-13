class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<int,int> mp;
        for(char c:s) mp[c]++;
        int ans = 0;
        for(char c : t){
            if(mp.find(c) == mp.end())ans++;
            else mp[c]--;
            if(mp[c] == 0)mp.erase(c);
        }
        return ans;
    }
};