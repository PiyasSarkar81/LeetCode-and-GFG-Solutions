//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int l = 0,r= n-1;
    sort(arr,arr+n);
    int ans1=-1,ans2=-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m]>x) r = m-1;
        else {
            ans1 = arr[m];
            l = m+1;
        }
    }
    l=0,r=n-1;
    while(l<=r) {
        int m = l+(r-l)/2;
        if(arr[m]>=x){
            ans2=arr[m];
            r=m-1;
        } else {
            l= m+1;
        }
    }
    return {ans1,ans2};
}