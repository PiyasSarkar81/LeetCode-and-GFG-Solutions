//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


    void dfs(vector<vector<char>>& ans, vector<vector<char>>& mat, int n, int m,int r, int c,int delRow[], int delCol[]) {
        ans[r][c]='Z';
        for(int i=0;i<4;i++){
            int nr = r + delRow[i];
            int nc = c + delCol[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]=='O' && ans[nr][nc]!='Z') dfs(ans,mat,n,m,nr,nc,delRow,delCol);
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<char>> ans = mat;
        int delRow[] = {0,0,1,-1};
        int delCol[] = {1,-1,0,0};
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O') dfs(ans,mat,n,m,i,0,delRow,delCol);
            if(mat[i][m-1]=='O') dfs(ans,mat,n,m,i,m-1,delRow,delCol);
        }
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O') dfs(ans,mat,n,m,0,i,delRow,delCol);
            if(mat[n-1][i]=='O') dfs(ans,mat,n,m,n-1,i,delRow,delCol);
        }
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
            if(ans[i][j]=='O')ans[i][j]='X';
            if(ans[i][j]=='Z')ans[i][j]='O';
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends