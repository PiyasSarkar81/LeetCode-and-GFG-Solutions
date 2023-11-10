class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> graph;
        for(auto &edges : adjacentPairs){
            graph[edges[0]].push_back(edges[1]);
            graph[edges[1]].push_back(edges[0]);
        }

        int root;
        for(auto& pair : graph){
            if(pair.second.size() == 1){
                root = pair.first;
                break;
            }
        }

        int curr = root;
        vector<int> ans = {root};
        int prev = INT_MAX;

        while(ans.size() < graph.size()){
            for(int nei : graph[curr]){
                if(nei != prev){
                    ans.push_back(nei);
                    prev = curr;
                    curr = nei;
                    break;
                }
            }
        }

        return ans;
    }
};