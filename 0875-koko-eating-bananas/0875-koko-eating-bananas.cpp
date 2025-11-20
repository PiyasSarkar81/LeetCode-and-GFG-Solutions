class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        int ans = r;
        while(l<=r){
            int m = l + (r-l)/2;
            long long cnt = 0;
            for(int i = 0;i<piles.size();i++){
                cnt += ceil((double)piles[i]/m);
                
            }
            if(cnt <= h) {
                ans = m;
                r = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};