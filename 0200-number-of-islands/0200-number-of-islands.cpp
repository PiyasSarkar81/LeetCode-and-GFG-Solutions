class Solution {
public:
    void mark_curr_island(vector<vector<char>>& grid,int x,int y,int row,int col){
        if(x<0 || x>=row || y<0 || y>=col || grid[x][y]!='1')
            return;
        grid[x][y] = '2';
        mark_curr_island(grid,x-1,y,row,col);
        mark_curr_island(grid,x,y-1,row,col);
        mark_curr_island(grid,x+1,y,row,col);
        mark_curr_island(grid,x,y+1,row,col);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        
        if(row==0) return 0;
        
        int col = grid[0].size();
        
        int noOfIslands = 0;
        
        for(int i =0;i<row;i++){
            for(int j =0;j<col;j++){
                if(grid[i][j]=='1'){
                    mark_curr_island(grid,i,j,row,col);
                    noOfIslands += 1;
                }
            }
        }
        return noOfIslands;
    }
};