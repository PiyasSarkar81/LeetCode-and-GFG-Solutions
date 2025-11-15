class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftFill = height[0], rightFill = height[n-1];
        vector<int> leftArr(n,0), rightArr(n,0);
        for(int i=0;i<n;i++){
            leftFill = max(leftFill, height[i]);
            rightFill = max(rightFill, height[n-1-i]);
            leftArr[i] = leftFill - height[i];
            rightArr[n-1-i] = rightFill - height[n-1-i]; 
        }
        int ans = 0;
        for(int i=0;i<n;i++) ans += min(leftArr[i], rightArr[i]);
        return ans;
    }
};