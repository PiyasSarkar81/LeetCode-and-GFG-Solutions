class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int ans = 0;
        sort(arr.begin(), arr.end());
        if(arr[0] != 1) {
            arr[0] = 1;
            ans++;
        }
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])>1){
                ans++;
                arr[i] = arr[i-1]+1;
            }
        }
        return arr[arr.size()-1];
    }
};