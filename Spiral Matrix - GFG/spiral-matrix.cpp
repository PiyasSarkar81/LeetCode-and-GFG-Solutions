//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int top = 0, bottom = n-1, left = 0, right = m-1;
        
        int d = 0;
        while(top<=bottom && left <=right) {
            if(d == 0){
                for(int i =left; i<=right; i++){
                 k--;
                 if(k ==0) return a[top][i];
                }
                top++;
                
            }
            else if(d == 1) {
                for(int i = top; i<=bottom; i++) {
                    k--;
                   if(k ==0) return a[i][right]; 
                }
                right--;
            }
            else if(d == 2) {
                for(int i = right; i>=left; i--) {
                    k--;
                   if(k ==0) return a[bottom][i]; 
                }
                bottom--;
            }
            else if(d == 3) {
                for(int i = bottom; i>=top; i--) {
                    k--;
                   if(k ==0) return a[i][left]; 
                }
                left++;
            }
            d = (d+1)%4;
        }
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends