class Graph {
    vector<vector<int>> adj;
public:
    Graph(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n,vector<int>(n,1e9));
        for(auto &e : edges){
            adj[e[0]][e[1]] = e[2];
        }
        for(int i=0;i<n;i++)
            adj[i][i] = 0;
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                for(int k =0;k<n;k++){
                    adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
                }
            }
        }
        
    }
    
    void addEdge(vector<int> edge) {
       int n = adj.size();
       for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                adj[i][j] = min(adj[i][j], adj[i][edge[0]]+ adj[edge[1]][j] + edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        if(adj[node1][node2] == 1e9) return -1;
        return adj[node1][node2];
            
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */