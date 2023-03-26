class Solution {
public:
    void dfs(int node, vector<int>& dist_node, vector<bool>& visited, vector<int>& edges, int dist, int& ans,vector<bool>& extra){
        if(node!=-1){ 
           if(!visited[node]){
                visited[node] = true;
                extra[node] = true;
                dist_node[node] = dist;
                dfs(edges[node],dist_node,visited,edges,1+dist,ans,extra);
           }
            else if(extra[node]){
                ans = max(ans,dist - dist_node[node]);
            }
            extra[node] = false;
        }
    }
    
    int longestCycle(vector<int>& edges) {
        vector<int> dist_node(edges.size(),0);
        vector<bool> visited(edges.size(),false);
        vector<bool> extra(edges.size(),false);
        int ans = -1;
        for(int i =0;i< edges.size();i++){
            if(!visited[i])
            dfs(i,dist_node,visited,edges,0,ans,extra);
        }
        return ans;
    }
};