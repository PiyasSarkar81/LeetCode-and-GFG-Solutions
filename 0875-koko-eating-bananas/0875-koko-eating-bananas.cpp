 #define ll long long int

class Solution {
public:
     bool isPossible(vector<int>& piles, ll rate, ll h){
     ll time =0;
     for(auto p: piles){
        time += p/rate;
        if(p%rate) time ++;
     }
     return time<=h;
 }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        ll ans = r;
        if(piles.size()>h) return -1;
        if(piles.size()==h) return r;
        while(l<=r){
            ll m = l + (r-l)/2;
            if(isPossible(piles,m,h)){
                ans = m;
                r = m-1;
            }
            else l = m+1;
        } 
        return (int)ans;
    }

};