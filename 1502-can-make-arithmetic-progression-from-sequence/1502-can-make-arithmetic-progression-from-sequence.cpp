class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int small = arr[0];
        int big = arr[1];
        int m = big - small;
        for(int i =2;i<arr.size();i++){
            small = big; 
            big = arr[i];
            if(big - small != m) return false;
        }
        return true;
    }
};