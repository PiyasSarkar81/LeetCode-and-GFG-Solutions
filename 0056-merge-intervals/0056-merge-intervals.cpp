class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        for(int i=0;i<intervals.size();i++){
            if(v.empty() || v.back()[1] < intervals[i][0]){
                vector<int> t = {intervals[i][0],intervals[i][1]};
                v.push_back(t);
            }
            else{
                v.back()[1] = max(v.back()[1], intervals[i][1]);
            }

        }
        return v;
    }
};