class Solution {
public:
    int shortestPathLength(vector<vector<int>>& G) {
        int n = G.size();
        queue<vector<int>>q;
        set<pair<int, int>>visited;
        int finalState = (1<<n)-1;
        
        for(int i=0; i<n; i++) {
            int mask = (1<<i);
            q.push({i, mask, 0});
            visited.insert({i, mask});
        }
        
        while(!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            if(curr[1] == finalState) return curr[2];
            
            for(auto g: G[curr[0]]) {
                int mask = curr[1];
                mask = mask | (1<<g);
                if(visited.find({g, mask}) == visited.end()) {
                    visited.insert({g, mask});
                    q.push({g, mask, curr[2]+1});
                }
            }
        }
        return -1;
    }
};