class Solution {
public:
    int mod = 1e9+7; 
    int numberOfWays(string corridor) {
        long cnt = 1;
        int seats = 0, prePair = -1;
        for(int i =0;i<corridor.size();i++){
            if(corridor[i] == 'S'){
                seats++;
                if(seats == 2){
                    prePair = i;
                    seats = 0;
                }
                else if(seats == 1 && prePair != -1){
                    cnt *= (i-prePair);
                    cnt %= mod;
                }
            }
        }
        if(seats == 1 || prePair == -1) return 0;
        return (int) cnt;
    }
};