//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// void swap(long long *xp, long long *yp)
// {
//     long long temp = *xp;
//     *xp = *yp;
//     *yp = temp;
// }

// int partition(long long arr[], int low, int high, int n)
// {
//     int pivot = arr[high];
//     int i= (low - 1),j;
//     for ( j = low; j <= high - 1; j++) {
//         if (arr[j] < pivot) {
//             i++; 
//             swap(&arr[i], &arr[j]);
//         }
	
//     }
//     swap(&arr[i + 1], &arr[high]);
    
//     return (i + 1);
// }

// void quickSort(long long arr[], int low, int high, int n)
// {
//     if (low < high) {
//         int pi = partition(arr, low, high, n);
//         quickSort(arr, low, pi - 1, n);
//         quickSort(arr, pi + 1, high, n);
//     }
// }

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	sort(arr,arr+n);
    	return max(arr[n-1]*arr[n-2]*arr[n-3], arr[0]*arr[1]*arr[n-1]);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends