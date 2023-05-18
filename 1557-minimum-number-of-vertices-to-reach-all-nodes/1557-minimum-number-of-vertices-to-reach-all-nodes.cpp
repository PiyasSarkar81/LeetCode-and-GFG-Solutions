class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<bool> indegree(n, false);
        for (vector<int> &it : edges) {
            indegree[it[1]] = true;
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            
            if (!indegree[i]) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};