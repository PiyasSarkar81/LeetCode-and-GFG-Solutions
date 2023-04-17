class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = *max_element(candies.begin(),candies.end());
        vector<bool> ans;
        for(auto c : candies){
            if(c+extraCandies >= m) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};