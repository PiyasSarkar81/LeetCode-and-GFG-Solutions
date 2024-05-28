class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start =0, current_cost = 0, max_length=0;
        for(int end = start;end<s.size();end++){
            current_cost += abs(s[end]-t[end]);
            if(current_cost > maxCost) {
                current_cost -= abs(s[start] - t[start]);
                start++;
            }
            max_length = max(max_length, end - start + 1);
        }
        return max_length;
    }
};