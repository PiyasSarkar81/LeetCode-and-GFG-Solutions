

class Solution {
    typedef long long ll;
    const static int MOD = 1e9 + 7;
public:
    
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].size();
        
        vector<vector<int>> freq(m,vector<int>(26,0));
        for(int j =0;j<m;j++){
            for(int i=0;i<n;i++){
                freq[j][words[i][j]-'a']++;
            }
        }
        
        vector<vector<int>> pos(26);
        
        int l = target.size();
        for(int i=0;i<l;i++) pos[target[i]-'a'].push_back(i);
        
        vector<ll> prev(l,0);
        vector<ll> curr(l,0);
        
        for(int i =0;i<m;i++){
            for(int j = 0;j<26;j++){
                for(auto p : pos[j]){
                    if(p==0) curr[p] += freq[i][j];
                    else curr[p] += prev[p-1]*freq[i][j];
                    curr[p] %= MOD;
                }
            }
            prev = curr;
        }
        return curr[l-1];
    }
};