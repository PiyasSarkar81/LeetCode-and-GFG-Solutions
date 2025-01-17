class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        bool ind = 0;
        for( int i =0;i<n-1;i++) {
            if(derived[i] == 1) {
                ind = !ind;
            }
        }
        if(derived[n-1] == 0 && ind == 0) return true;
        if(derived[n-1] == 1 && ind == 1) return true;
        return false;
    }
};