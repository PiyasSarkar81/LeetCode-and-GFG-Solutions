//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int dx[] = {0,0,1,-1,-1,-1,1,1};
        int dy[] = {1,-1,0,0,-1,1,-1,1};
        
        int ans =0;
        
        for(int i =0;i<matrix.size();i++){
            for(int j =0;j<matrix[0].size();j++){
                int temp = 0;
                if(matrix[i][j] == 1){
                    for(int k =0;k<8;k++){
                        int x = i + dx[k], y = j + dy[k];
                        if(x>=0 && y>=0 && x<matrix.size() && y < matrix[0].size()){
                            if(matrix[x][y]==0) temp++;
                        }
                    }
                }
                if(temp > 0 && temp%2==0) ans++;
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends