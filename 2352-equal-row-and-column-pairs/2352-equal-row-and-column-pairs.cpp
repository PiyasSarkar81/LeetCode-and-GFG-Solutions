class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt =0;
        map<vector<int>, int>mp;
        for(auto g: grid){
            mp[g]++;
        }

        for(int i=0;i<grid[0].size();i++){
            vector<int>v;
            for(int j=0;j<grid.size();j++){
                v.push_back(grid[j][i]);
            }
            cnt+=mp[v];
        }
        return cnt;
    }
};