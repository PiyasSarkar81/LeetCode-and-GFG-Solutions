//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int exe = 0;
        int n = str.size();
        int ans = 0;
        for(int i = n-1;i>=0;i--){
            if(i==0 && str[i]== '-') ans = -ans;
            else if(str[i] < '0' || str[i] > '9') return -1;
            else {
                ans +=(str[i]-'0') * pow(10,exe);
                exe++;
            }
            
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends