class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int leftMost, rightMost;
        if(!left.empty()) leftMost = *max_element(left.begin(),left.end());
        else leftMost = 0;
        if(!right.empty()) rightMost = *min_element(right.begin(), right.end());
        else rightMost = n;
        return max(leftMost,n-rightMost);

    }
};