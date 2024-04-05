class Solution {
public:
    string makeGood(string s) {
        string res;
        for (char c : s) {
            if (!res.empty() && (toupper(c) == toupper(res.back())) && (c - res.back() != 0)) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }
        
        return res;
    }
};