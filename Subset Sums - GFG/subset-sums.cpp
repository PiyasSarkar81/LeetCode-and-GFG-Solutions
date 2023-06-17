//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void solve(int inx, int n, vector<int>& ans, vector<int> &arr, int sum){
        if(inx == n){
            ans.push_back(sum);
            return;
        }
        
        // pick up the inx element
        solve(inx+1, n, ans, arr, sum + arr[inx]);
        
        // not to pick up
        solve(inx+1, n, ans, arr, sum);
    }
    
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        
        // BIT MANIPULATION
//         vector<int>ans;
// 	    for (int num = 0; num < (1 << n); num++) {
// 		int temp = 0;
// 		for (int i = 0; i < n; i++) {
// 			//check if the ith bit is set or not
// 			if (num & (1 << i)) {
// 				temp += arr[i];
// 			}
// 		}

// 		ans.push_back(temp);

// 	}
// 	sort(ans.begin(), ans.end());
// 	return ans;


    // REcurtion
    
    vector<int> ans;
    solve(0,n,ans,arr,0);
    sort(ans.begin(),ans.end());
    return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends