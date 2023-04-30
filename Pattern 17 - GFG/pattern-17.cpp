//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        char a;
        for(int i =1;i<=n;i++){
            a ='A';
            for(int j =1;j<=n-i;j++)
            cout<<" ";
            for(int j =0;j<i;j++)
            cout<<a++;
            a -=2;
            for(int j = i-1;j>=1;j--)
            cout<<a--;
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