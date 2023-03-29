class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size(), total = 0,ans = 0;
        for(int i =n-1;i>=0 && satisfaction[i]>-total;i--){
            total += satisfaction[i];
            ans += total;
        }
        return ans;
    }
};