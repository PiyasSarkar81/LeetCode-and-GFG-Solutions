class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n+1];
        vector<int> indegree(n+1);
        for(auto &r : relations){
            adj[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }

        // store the tasks which start from the get go
        queue<int> q;
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            if(indegree[i] == 0){
                q.push(i);
                dp[i] = time[i-1];
            }
        }

        // topo sort
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int node = q.front();
                q.pop();

                for(auto &adjNode : adj[node]){
                    dp[adjNode] = max(dp[adjNode], dp[node]+time[adjNode-1]);
                    indegree[adjNode]--;
                    if(indegree[adjNode]==0)q.push(adjNode);
                }
            }
        }
        
        return *max_element(dp.begin(),dp.end()); 
    }
};