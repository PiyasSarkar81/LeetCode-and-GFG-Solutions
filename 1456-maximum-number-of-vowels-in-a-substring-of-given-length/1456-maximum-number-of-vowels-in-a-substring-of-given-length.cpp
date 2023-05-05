class Solution {
public:
    int vow[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
    
    int maxVowels(string s, int k) {
        int max_vow = 0;
        for(int i = 0, curr_vow = 0; i<s.size(); i++){
            curr_vow += vow[s[i] - 'a'];
            if(i>=k){
                curr_vow -= vow[s[i-k] - 'a'];
            }
            max_vow = max(max_vow,curr_vow);
        }
        return max_vow;
    }
};