class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char,int> countT, window;
        for(auto c : t) countT[c]++;

        int l = 0, need = countT.size(), count = 0, currLength = INT_MAX;
        pair<int,int> pos = {-1,-1};

        for(int r = 0; r<s.size();r++){
            char c = s[r];
            window[c]++;
            if(countT.count(c) && countT[c] == window[c]){
                count++;
            }
            while(count == need){
                int len = r-l+1;
                if(len < currLength){
                    currLength = len;
                    pos = {l,r};
                }

                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    count--;
                }
                l++;
            }
        }

        return currLength == INT_MAX ? "" : s.substr(pos.first, currLength);
    }
};