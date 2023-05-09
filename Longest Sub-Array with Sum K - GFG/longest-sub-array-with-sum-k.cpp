//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        map<long long,int> prefixSum;
        long long sum = 0;
        int maxLen = 0;
        for(int i =0;i<N;i++){
            sum += A[i];
            if(sum == K){
                maxLen = max(maxLen, i+1);
            }
            long long rem = sum - K;
            if(prefixSum.find(rem) != prefixSum.end()){
                int len = i - prefixSum[rem];
                maxLen = max(maxLen, len);
            }
            if(prefixSum.find(sum) == prefixSum.end()){
                prefixSum[sum] = i;
            }
        }
        return maxLen;
        
        
        // Optimal sol for positive and zero
        // int left = 0,right = 0, maxLen = 0;
        // long long sum = A[0];
        // while(right < N){
        //     while(sum > K && left<= right){
        //         sum -= A[left];
        //         left++;
        //     }
        //     if(sum == K) maxLen = max(maxLen, right - left + 1);
        //     right++;
        //     if(right<N) sum += A[right];
        // }
        // return maxLen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends