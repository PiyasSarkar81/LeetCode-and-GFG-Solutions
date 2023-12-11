class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<= (n*3)/4;i++){
            if(arr[i] == arr[i + n/4]) 
                return arr[i];
        }
        return arr[0];
    }
};