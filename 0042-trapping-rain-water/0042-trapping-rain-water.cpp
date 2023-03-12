class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0,r=n-1;
        int res=0,lH=0,rH=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(height[l]>=lH) lH = height[l];
                else res += lH - height[l];
                l++;
            }
            else{
                if(height[r]>=rH) rH = height[r];
                else res += rH - height[r];
                r--;
            }
        }
        return res;
        
    }
};