class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int temp = 0;
        int n = pref.size();
        for(int i=1;i<n;i++){
            temp = temp^pref[i-1];
            pref[i] ^= temp;
        }
        return pref;
    }
};