class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> outDegree(n), safe(n), ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            for(int v:graph[i]){
                adj[v].push_back(i);
            }
            outDegree[i] = graph[i].size();
            if(outDegree[i] == 0)q.push(i);
        }
        while(q.size()){
            int u = q.front();
            q.pop();
            safe[u] = 1;
            for(int v : adj[u])
                if(--outDegree[v] == 0) q.push(v);
        }
        for(int i=0;i<n;i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};