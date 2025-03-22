class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(const auto& edge : edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int completeComponents = 0;

        for(int vertex = 0; vertex < n; vertex++){
            if(!vis[vertex]){
                vector<int> component;
                queue<int> q;
                q.push(vertex);
                vis[vertex] = true;

                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    component.push_back(curr);

                    for(int neg: graph[curr]){
                        if(!vis[neg]){
                            q.push(neg);
                            vis[neg] = true;
                        }
                    }
                }

                bool isComplete = true;
                for(int node : component){
                    if(graph[node].size() != component.size()-1){
                        isComplete = false;
                        break;
                    }
                }

                if(isComplete) completeComponents++;
            }
        }

        return completeComponents;
    }
};