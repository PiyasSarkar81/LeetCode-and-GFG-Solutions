class Solution {
    bool isValid(int row,int col,vector<string>& board,int n){
        int prow = row;
        int pcol = col;
        
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;col--;
        }
        
        row = prow;
        col = pcol;
        
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        
        row = prow;
        col = pcol;
        
        while(col>=0 && row<n){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    
    void solve(int col,int n,vector<vector<string>>& ans,vector<string>& board){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isValid(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,n,ans,board);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i =0;i<n;i++)
            board[i] = s;
        solve(0,n,ans,board);
        return ans;
    }
};