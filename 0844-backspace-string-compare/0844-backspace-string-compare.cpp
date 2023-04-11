class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string S,T;
        for(auto c : s){
            if(c !='#') S += c;
            else if(S=="") continue;
            else S.pop_back();
        }
        for(auto b : t){
            if(b !='#') T += b;
            else if(T=="" ) continue;
            else T.pop_back();
        }
        int n = S.size();
        if(n != T.size()) return false;
        for(int i =0;i<n ;i++){
            if(S[i]!=T[i]) return false;
        }
        return true;
    }
};