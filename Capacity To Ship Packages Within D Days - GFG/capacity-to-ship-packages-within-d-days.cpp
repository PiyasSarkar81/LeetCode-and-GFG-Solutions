//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool isPossible(int arr[], int N, int mid, int D){
        int d = 1;
        int sum = 0;
        for(int i =0;i<N;i++){
            sum += arr[i];
            if(sum>mid){
                d++;
                sum=arr[i];
            }
        }
        if(d<=D) return true;
        return false;
    }
  
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        int low = *max_element(arr, arr+N);
        int high = 0;
        for(int i =0;i<N;i++) high += arr[i];
        if(D>=N) return low;
        int ans = 0;
        while(low<=high){
            int mid = (low + high) >> 1;
            if(isPossible(arr,N,mid,D)){
                ans = mid;
                high = mid -1;
            } else low = mid +1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends