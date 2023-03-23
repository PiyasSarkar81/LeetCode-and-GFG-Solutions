class Solution {
    void dfs(unordered_map<int,vector<int>>& adj, int s,vector<bool>& vis){
        vis[s] = true;
        for(int i =0;i<adj[s].size();i++){
            if(vis[adj[s][i]]==false){
                dfs(adj,adj[s][i],vis);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n,false);
        unordered_map<int,vector<int>> adj;
        int edges = 0;
        // STEP1 : Adjusency list
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }
        
        // STEP 2 : Find no of components
        int components = 0;
        for(int i =0;i<n;i++){
            if(visited[i]==false){
                components++;
                dfs(adj,i,visited);
            }
        }
        
        //STEP 3 : no of redundent edges
        if(edges<(n-1)) return -1;
        int redundent = edges - (n-1) + (components-1);
        if(redundent >= (components -1)) return (components -1);
        return -1;
        
    }
};