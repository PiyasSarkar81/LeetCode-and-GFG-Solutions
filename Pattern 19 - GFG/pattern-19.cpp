//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        int spaces = 0;
        for(int i =0;i<n;i++){
            for(int j=1;j<=n-i;j++)
                cout<<"*";
            for(int j =0;j<spaces;j++)
            cout<<" ";
            for(int j=1;j<=n-i;j++)
            cout<<"*";
            spaces += 2;
            
            cout<<endl;
        }
        for(int i =1;i<=n;i++){
            spaces -= 2;
            for(int j=1;j<=i;j++)
                cout<<"*";
            for(int j =0;j<spaces;j++)
            cout<<" ";
            for(int j=1;j<=i;j++)
            cout<<"*";

            cout<<endl;
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends