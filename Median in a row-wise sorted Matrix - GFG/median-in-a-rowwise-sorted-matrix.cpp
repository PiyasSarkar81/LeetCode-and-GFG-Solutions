//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int countEle(vector<int>& row, int mid){
        int n = row.size();
        int l =0,r=n-1;
        while(l<=r){
            int m = (l+r) >> 1;
            if(row[m] <= mid) l = m+1;
            else r = m-1;
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 1, h = 1e9;
        
        while(l<=h){
            int mid = (l+h) >> 1;
            int cnt =0;
            
            for(int i =0;i<n;i++){
                cnt += countEle(matrix[i], mid); 
            }
            
            if(cnt<= (n*m)/2) l = mid+1;
            else h = mid-1;
        }
        return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends