class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j] == 1){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            auto e = q.front();
            q.pop();
            int i = e.first, j = e.second;
            for(auto &d : dir){
                int x = i+d[0], y = j+d[1];
                if(x>=0 && y>=0 && x<n && y<m && ans[x][y] == -1) {
                    ans[x][y] = ans[i][j] + 1;
                    q.push({x,y});
                }
            }
        }

        return ans;
    }
};