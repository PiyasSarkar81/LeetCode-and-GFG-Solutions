class Solution {
public:
    // is it possible to shipty in D days
    bool isPossible(vector<int>& wt, int D, int mid){
        int d = 1;
        int sum = 0;
        for(auto w : wt){
            sum+= w;
            if(sum > mid){
                sum = w;
                d++;
            }
        }
        if(d<=D) return true;
        return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = 0;
        for(auto &w: weights) high += w;
        while(low<= high){
           int mid = (low+high)>>1;
            if(!isPossible(weights,days,mid)) low = mid +1;
            else high = mid -1;
        }
        return low;
    }
};