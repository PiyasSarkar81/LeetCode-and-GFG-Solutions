class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r= height.size()-1;
        int curr = min(height[l],height[r]) * (r-l);
        while(l<r){
            if(height[r] < height[l]) r--;
            else l++;
            int newVal = min(height[l],height[r]) * (r-l);
            curr = max(curr, newVal);
        }
        return curr;
    }
};