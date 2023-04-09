class Solution {
    typedef array<int, 26> T;
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        int n = colors.size();
        vector<int> indegree(n);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        vector<T> cnt(n,T{});
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                cnt[i][colors[i]-'a'] =1;
            }
        }
        int ans =0,seen =0;
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            int val = *max_element(cnt[u].begin(),cnt[u].end());
            ans = max(ans,val);
            seen++;
            for(int v:adj[u]){
                for(char i =0;i<26;i++){
                    cnt[v][i] = max(cnt[v][i], cnt[u][i] + (i == colors[v]-'a'));
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return seen < colors.size() ? -1 : ans;
    }
};