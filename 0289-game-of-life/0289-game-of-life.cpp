class Solution {
public:
    bool validNeighbour(vector<vector<int>>& board,int x,int y){
        return (x>=0 && x<board.size() && y>=0 && y<board[0].size());
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx = {0,0,1,1,1,-1,-1,-1};
        vector<int> dy = {1,-1,1,-1,0,0,1,-1};
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                int cnt = 0;
                for(int k =0;k<8;k++){
                    int x = i+dx[k], y = j + dy[k];
                    if(validNeighbour(board,x,y) && abs(board[x][y]) == 1)
                        cnt++;
                }
                if(board[i][j] == 1 &&( cnt > 3 || cnt <2)) board[i][j] = -1;
                if(board[i][j] == 0 && cnt == 3) board[i][j] = 2;
            }
            
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j] >= 1) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};