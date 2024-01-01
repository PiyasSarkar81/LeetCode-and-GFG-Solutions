class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size(), i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;
        while(i<n && j<m){
            if(s[j] >= g[i]){
                ans++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};