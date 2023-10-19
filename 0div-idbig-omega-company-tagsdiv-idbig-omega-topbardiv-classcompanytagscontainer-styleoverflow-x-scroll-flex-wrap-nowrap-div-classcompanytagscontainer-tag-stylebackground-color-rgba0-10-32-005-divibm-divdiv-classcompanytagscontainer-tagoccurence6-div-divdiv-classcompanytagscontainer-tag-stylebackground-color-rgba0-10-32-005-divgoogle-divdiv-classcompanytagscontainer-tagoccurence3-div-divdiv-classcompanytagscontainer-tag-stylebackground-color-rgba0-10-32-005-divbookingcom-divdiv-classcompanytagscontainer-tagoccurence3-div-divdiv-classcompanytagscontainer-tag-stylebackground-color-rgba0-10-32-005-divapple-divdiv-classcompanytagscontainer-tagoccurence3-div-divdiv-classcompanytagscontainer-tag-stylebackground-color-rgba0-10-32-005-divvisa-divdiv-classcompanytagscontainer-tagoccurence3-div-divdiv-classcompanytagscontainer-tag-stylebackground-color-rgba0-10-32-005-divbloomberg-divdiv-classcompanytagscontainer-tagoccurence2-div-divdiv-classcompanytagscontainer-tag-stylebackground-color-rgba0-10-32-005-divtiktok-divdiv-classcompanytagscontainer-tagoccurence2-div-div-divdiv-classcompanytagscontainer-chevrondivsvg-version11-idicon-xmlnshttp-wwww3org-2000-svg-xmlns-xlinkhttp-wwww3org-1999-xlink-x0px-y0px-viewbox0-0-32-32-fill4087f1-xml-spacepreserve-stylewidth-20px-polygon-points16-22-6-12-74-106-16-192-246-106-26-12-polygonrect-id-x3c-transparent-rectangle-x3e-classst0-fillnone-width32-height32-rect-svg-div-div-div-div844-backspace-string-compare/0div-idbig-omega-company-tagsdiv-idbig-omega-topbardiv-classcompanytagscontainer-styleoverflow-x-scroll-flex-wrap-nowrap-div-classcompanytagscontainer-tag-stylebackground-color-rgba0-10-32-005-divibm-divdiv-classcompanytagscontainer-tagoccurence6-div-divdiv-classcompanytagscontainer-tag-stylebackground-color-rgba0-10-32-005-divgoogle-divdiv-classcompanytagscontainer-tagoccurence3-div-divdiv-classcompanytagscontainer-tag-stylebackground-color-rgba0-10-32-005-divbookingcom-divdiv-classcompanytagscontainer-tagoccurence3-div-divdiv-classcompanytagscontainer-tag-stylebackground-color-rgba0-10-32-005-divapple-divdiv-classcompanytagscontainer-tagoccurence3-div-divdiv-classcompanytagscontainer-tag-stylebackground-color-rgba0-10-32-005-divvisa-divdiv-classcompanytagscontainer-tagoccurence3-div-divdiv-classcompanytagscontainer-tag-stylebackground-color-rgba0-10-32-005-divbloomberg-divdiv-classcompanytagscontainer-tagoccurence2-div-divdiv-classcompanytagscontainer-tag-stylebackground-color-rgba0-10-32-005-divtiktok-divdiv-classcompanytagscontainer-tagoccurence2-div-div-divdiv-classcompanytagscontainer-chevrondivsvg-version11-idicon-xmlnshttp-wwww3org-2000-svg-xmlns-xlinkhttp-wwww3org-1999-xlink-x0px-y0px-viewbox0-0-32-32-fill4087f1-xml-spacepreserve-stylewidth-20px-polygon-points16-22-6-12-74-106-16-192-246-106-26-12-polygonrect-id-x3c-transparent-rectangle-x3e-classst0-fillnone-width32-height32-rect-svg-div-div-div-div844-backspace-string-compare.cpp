class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string l1 = "", l2 = "";
        for(int i=0;i<s.size();i++){
            if( l1 != "" && s[i] == '#') l1.pop_back();
            else if(l1 == "" && s[i] == '#') l1 = "";
            else l1.push_back(s[i]);
        }
        for(int i=0;i<t.size();i++){
            if( l2 != "" && t[i] == '#') l2.pop_back();
            else if(l2 == "" && t[i] == '#') l2 = "";
            else l2.push_back(t[i]);
        }
        if(l1 == l2) return true;
        return false;
    }
};