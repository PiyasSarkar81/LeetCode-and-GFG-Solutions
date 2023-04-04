//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    unordered_map<char,int> ch;
    ch[str[0]] = 1;
    for(int i =1;i<str.size();i++){
        if(str[i]!=str[i-1]) ch[str[i]]++;
    }
    int mini = min(ch['a'],ch['b']);
    return mini+1;
    
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends