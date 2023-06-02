//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    
    bool isPossible(int A[], int N,int M,int mid){
        int alloStd = 1,pages=0;
        for(int i=0;i<N;i++){
            if(A[i]>mid) return false;
            if(A[i]+pages > mid) {
                alloStd++;
                pages = A[i];
            } else {
                pages += A[i];
            }
        }
        if(alloStd > M) return false;
        return true;
    }
    
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int low = *min_element(A,A+N);
        int high = 0;
        for(int i =0;i<N;i++) high += A[i];
        if(M>N) return -1;
        int ans = -1;
        
        while(low<=high) {
            int mid = (low+high) >> 1;
            
            if(isPossible(A,N,M,mid)){
                ans = mid;
                high = mid -1;
            } else low = mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends