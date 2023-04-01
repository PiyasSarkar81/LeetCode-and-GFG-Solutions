//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minOperations(int N) {
        // Code here
         if(N%2==1){
            N--;
            int div=N/2;
            return (long)(div)*(div+1);
        }
        else{
            N--;
            int div=N/2;
            return (long)(div+1)*(div+2)/2+(long)(div)*(div+1)/2;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends