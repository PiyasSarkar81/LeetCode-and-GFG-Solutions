class Solution {
public:
    #define ll long long int
    
    void dfs(vector<vector<ll>>& adj,vector<bool>& vis,ll i,ll &cnt){
        cnt++;
        vis[i] = true;
        for(auto a : adj[i]){
            if(!vis[a]){
                dfs(adj,vis,a,cnt);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<ll>> adj(n);
        for(int i =0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        ll ans = ((ll)n*(n-1))/2;
        vector<bool> vis(n,false);
        for(ll i=0;i<n;i++)
        {
            if(!vis[i])
            {
                ll cnt=0;
                dfs(adj,vis,i,cnt);
                ans -= (cnt*(cnt-1))/2;
            }
        }
        return ans;
    }
};