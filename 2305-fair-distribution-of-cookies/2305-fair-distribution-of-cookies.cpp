class Solution {
public:

    int dfs(int i,vector<int>& dis, vector<int>& cookies, int k, int zeroCount) {
        if(cookies.size() - i < zeroCount) return INT_MAX;
        if(i == cookies.size()) return *max_element(dis.begin(), dis.end());
        int ans = INT_MAX;
        for(int j =0;j<k;j++){
            zeroCount -= dis[j] == 0?1:0;
            dis[j] += cookies[i];
            ans = min(ans, dfs(i+1,dis,cookies,k,zeroCount));
            dis[j] -= cookies[i];
            zeroCount += dis[j]==0?1:0;
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dis(k,0);
        return dfs(0,dis,cookies,k,k);
    }
};