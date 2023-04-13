//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long minDifference(int N, vector<int> &A) {
        // code here
        long long prefixSums[N + 1];
        prefixSums[0] = 0;
        for (int i = 1; i <= N; i++) {
            prefixSums[i] = prefixSums[i - 1] + A[i - 1];
        }
        long long smallestDifference = prefixSums[N];
        for (int i = 1; i < N - 2; i++) {
            pair<long long, long long> leftMinMax = getMinMaxSums(prefixSums, 1, i + 1);
            pair<long long, long long> rightMinMax = getMinMaxSums(prefixSums, i + 2, N);
            long long maxSumPQ = leftMinMax.second;
            long long maxSumRS = rightMinMax.second;
            long long minSumPQ = leftMinMax.first;
            long long minSumRS = rightMinMax.first;
            long long absoluteDifference = abs(max(maxSumPQ, maxSumRS) - min(minSumPQ, minSumRS));
            smallestDifference = min(smallestDifference, absoluteDifference);
        }
    return smallestDifference;
}

pair<long long, long long> getMinMaxSums(long long prefixSums[], int left, int right) {
    int lo = left, hi = right - 1;
    long long minSum = 0, maxSum = prefixSums[right] - prefixSums[left - 1];
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        long long leftSum = prefixSums[mid] - prefixSums[left - 1];
        long long rightSum = prefixSums[right] - prefixSums[mid];
        if (abs(rightSum - leftSum) < maxSum - minSum) {
            minSum = min(leftSum, rightSum);
            maxSum = max(leftSum, rightSum);
        }
        if (leftSum < rightSum) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return {minSum, maxSum};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends