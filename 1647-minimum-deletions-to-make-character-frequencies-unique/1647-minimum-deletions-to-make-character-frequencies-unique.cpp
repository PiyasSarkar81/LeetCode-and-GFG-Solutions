class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26);
        for(auto e : s){
            v[e-'a']++;
        }
        sort(v.begin(),v.end(),greater<int>());
        int max_alo  = v[0];
        int ans =0;
        for(auto f : v){
            if(f>max_alo){
                if(max_alo>0)
                    ans += (f-max_alo);
                else 
                    ans += f;
            }
            max_alo = min(max_alo-1,f-1);
        }
        return ans;
    }
};