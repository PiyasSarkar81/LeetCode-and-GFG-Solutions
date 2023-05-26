//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int l =0,r=n-1;
    int ans1 = -1,ans2=-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m]==x){
            ans1= m;
            r= m-1;
        }    
        else if(arr[m]>x) r = m-1;
        else {
            l = m+1;
        }
    }
    l =0,r=n-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m]==x){
            ans2= m;
          l = m +1;
        } else if(arr[m]<x) l = m+1;
        else {
            r = m-1;
        }
    }
    if(ans1==-1) return 0;
    return ans2-ans1+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends