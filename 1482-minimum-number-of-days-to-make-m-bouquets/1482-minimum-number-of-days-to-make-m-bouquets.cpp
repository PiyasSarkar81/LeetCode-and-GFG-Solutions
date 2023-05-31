class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), left = 1,right = 1e9;
        if((long) m * k > n) return -1;
        while(left < right){
            int mid = (left + right) >> 1;
            int flow = 0,bouq =0;
            for(int i=0;i<n;i++){
                if(bloomDay[i] > mid) flow = 0;
                else if(++flow >= k){
                    bouq++;
                    flow = 0;
                }
            }
            if(bouq < m){
                left = mid + 1;
            } else right = mid;
        }
        return left;
    }
};