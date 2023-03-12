class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro =0;
        int minPrise = INT_MAX;
        int n = prices.size();
        for(int i=0;i<n;i++){
            minPrise = min( minPrise, prices[i]);
            maxPro = max(maxPro, prices[i]-minPrise );

        }
        return maxPro;
    }
};