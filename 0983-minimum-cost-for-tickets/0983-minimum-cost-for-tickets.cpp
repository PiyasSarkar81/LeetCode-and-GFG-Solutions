class Solution {
public:
    int dfs(int i, vector<int>& days, vector<int>& costs, vector<int>& memo) {
        if (i >= days.size()) return 0;
        if (memo[i] != -1) return memo[i];
        int option1 = costs[0] + dfs(i + 1, days, costs, memo);

        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) j++;
        int option2 = costs[1] + dfs(j, days, costs, memo);

        j = i;
        while (j < days.size() && days[j] < days[i] + 30) j++;
        int option3 = costs[2] + dfs(j, days, costs, memo);

        return memo[i] = min({option1, option2, option3});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1);
        return dfs(0, days, costs, memo);
    }
};
