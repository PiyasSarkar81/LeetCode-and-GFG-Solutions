class Solution {
public:
    
    
    
    
    
    bool isCycle( vector<vector<int>>& adj,vector<int>& vis,int V){
        if(vis[V]==2) return true;
        vis[V] = 2;
        for(int i =0;i<adj[V].size();i++){
            if(vis[adj[V][i]]!=1)
                if(isCycle(adj,vis,adj[V][i]))
                    return true;
        }
        vis[V] =1;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(int i =0;i<prerequisites.size();i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        vector<int> visited(numCourses,0);
        
        for(int i =0;i<numCourses;i++){
            if(visited[i] == 0)
                if(isCycle(adj,visited,i)){
                    return false;
                }
        }
        return true;
    }
};