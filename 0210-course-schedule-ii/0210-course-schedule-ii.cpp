class Solution {
public:
    bool isCycleHelp(vector<vector<int>>& adj,vector<int>& vis, int v){
        if(vis[v]==1) return true;
        if(vis[v]==2) return false;
        
        vis[v] = 1; //mark as prosessing
        for(int i = 0;i<adj[v].size();i++){
            if(isCycleHelp(adj,vis,adj[v][i])) return true;
        }
        vis[v] = 2; //mark as procesed
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj,int n){
        vector<int> vis(n,0);
        for(int i = 0;i<n;i++ ){
            if(!vis[i]) 
                if(isCycleHelp(adj,vis,i))
                    return true;
        }
        return false;
    }
    
    void dfs(vector<vector<int>>& adj,int v,stack<int>& st,vector<bool>& vis){
        vis[v] = true;
        for(int i = 0;i<adj[v].size();i++){
            if(!vis[adj[v][i]]) dfs(adj,adj[v][i],st,vis);
        }
        st.push(v);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> ans;
        if(isCycle(adj,numCourses)) return ans;
        
        stack<int> st;
        vector<bool> vis(numCourses,false);
        
        for(int i =0;i<numCourses;i++){
            if(!vis[i]) dfs(adj,i,st,vis);
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};