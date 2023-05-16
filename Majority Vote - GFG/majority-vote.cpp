//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        int cnt1 = 0, cnt2 =0, ele1, ele2;
       for(int i =0;i<n;i++) {
           if(ele1 == nums[i] ) cnt1++;
           else if(ele2 == nums[i] ) cnt2++;
           else if(cnt1 == 0) {
               ele1 = nums[i];
               cnt1 = 1;
           }
           else if(cnt2 == 0) {
               ele2 = nums[i];
               cnt2 = 1;
           }
           else {
               cnt1--,cnt2--;
           }
       }
       cnt1 = cnt2 = 0;
       for(int i =0;i<n;i++) {
           if(ele1 == nums[i]) cnt1++;
           if(ele2 == nums[i]) cnt2++;
       }
       vector<int> ans;
       if(cnt1 > n/3) ans.push_back(ele1);
       if(cnt2 > n/3) ans.push_back(ele2);
       
       if(ans.empty()) ans.push_back(-1);
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends