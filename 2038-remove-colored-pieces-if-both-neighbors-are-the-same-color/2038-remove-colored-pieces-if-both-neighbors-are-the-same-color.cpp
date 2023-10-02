class Solution {
public:
    bool winnerOfGame(string colors) {
        unordered_map<char,int> mp;
        for(auto it = colors.begin();it != colors.end();){
            char color = *it;
            auto pos = it;
            while(pos != colors.end() && *pos == color) pos++;
            mp[color] += max(int(distance(it,pos)-2),0);
            it = pos;
        }
        if(mp['A']>mp['B']) return true;
        return false;
    }
};