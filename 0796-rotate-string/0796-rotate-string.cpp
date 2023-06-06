class Solution {
public:
    bool rotateString(string s, string goal) {
        string t = s+s;
        int n = s.size();
        int m = goal.size();
        if(n!=m) return false;
        for(int i =0;i<t.size();i++){
            if(t.substr(i,m)==goal)return true;
        }
        return false;
    }
};