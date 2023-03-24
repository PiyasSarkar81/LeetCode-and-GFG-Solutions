class Solution {
    int dfs(vector<vector<int>> &adj, vector<bool>& vis, int root){
        auto change = 0;
        vis[root] = true;
        for(auto to : adj[root]){
            if(!vis[abs(to)])
                change += dfs(adj,vis,abs(to)) + (to>0);
        }
        return change;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &c : connections){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        vector<bool> vis(n);
        return dfs(adj,vis,0);
    }
};