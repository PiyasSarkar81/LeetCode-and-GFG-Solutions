class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> res, mono;
        for (int o : obstacles) {
            int l = 0, r = mono.size();
            while (l < r) {
                int m = (l + r) / 2;
                if (mono[m] <= o)
                    l = m + 1;
                else
                    r = m;
            }
            res.push_back(l + 1);
            if (mono.size() == l)
                mono.push_back(o);
            mono[l] = o;
        }
        return res;
    }
};