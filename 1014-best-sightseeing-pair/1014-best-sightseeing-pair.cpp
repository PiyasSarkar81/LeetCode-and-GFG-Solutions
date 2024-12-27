class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        // vector<int> leftS(n);
        int leftS = values[0];

        int ans = 0;

        for(int i=1;i<n;i++){
            int currRS = values[i]-i;
            ans = max(ans, leftS+currRS);

            int currLS = values[i]+i;
            leftS = max(leftS, currLS);
        }

        return ans;
    }
};