class Solution {
public:
    bool isPossible(int mid, vector<int>&  dist, double hour){
        double time = 0;
        for(int i=0;i<dist.size()-1;i++){
            time += ceil((double)dist[i]/mid);
        }
        time += ((double)dist.back())/mid;
        if(time<=hour) return true;
        return false;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
       int n = dist.size();
       if(n>ceil(hour)) return -1;  // boundary case
       int i =1, j = 1e7, ans = -1;
       while(i<=j){
           int mid = (i+j)>>1;
           if(isPossible(mid,dist,hour)){  // if it possible to travel then look for the leaser speed
               ans = mid;
               j = mid -1;
           } else {
               i = mid +1;
           }
       }
       return ans;
    }
};