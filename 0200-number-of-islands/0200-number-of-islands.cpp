class Solution {
    void dfs(vector<vector<char>>& grid, int i,int j){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || j<0 || i== n || j==m || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m = grid[0].size(), island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1') {
                    island++;
                    dfs(grid,i,j);
                }
            }
        }
        return island;
    }
};