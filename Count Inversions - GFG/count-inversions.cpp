//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int marge(long long arr[], long long temp[], int left, int mid, int right) {
        long long int cnt = 0;
        int i = left, k = left, j = mid;
        while(i <= mid-1 && j <= right) {
            if(arr[i] <= arr[j] ) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                cnt += (mid - i);
            }
        }
        while(i<=mid-1) temp[k++] = arr[i++];
        while(j<=right) temp[k++] = arr[j++];
        for(int i =left;i<=right;i++) arr[i] = temp[i];
        return cnt;
    }
    
    
    
    long long int margeSort(long long arr[], long long temp[], int left, int right){
        int mid;
        long long int cnt = 0;
        if(left<right) {
            mid = left + (right - left)/2;
            
            cnt += margeSort(arr,temp,left,mid);
            cnt += margeSort(arr,temp,mid+1,right);
            
            cnt += marge(arr,temp,left,mid+1,right);
        }
        return cnt;
    }
    
    
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long temp[n];
        return margeSort(arr,temp,0,n-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends