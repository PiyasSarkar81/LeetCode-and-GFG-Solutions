class Solution {
public:
    
    int length(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& path){
        int n= matrix.size();
        int m = matrix[0].size();
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        
        if(path[i][j]>0) return path[i][j];
        
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        
        int currmax = 1;
        for(int k=0;k<4;k++){
            int x = i+dx[k], y = j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m)
                if(matrix[i][j]<matrix[x][y] )
                    currmax = max(currmax,1+length(matrix,x,y,path));
            
        }
        path[i][j] = currmax;
        return currmax;
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>path(n,vector<int>(m,0));
        
        int maxi = 0;
        
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                maxi = max(maxi,length(matrix,i,j,path));
            }
        }
        return maxi;
    }
};