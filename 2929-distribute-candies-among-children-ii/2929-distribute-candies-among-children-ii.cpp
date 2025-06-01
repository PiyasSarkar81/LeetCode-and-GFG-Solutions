class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto com = [](int n) {
            return 1LL * n * (n - 1) / 2;
        };
        if (n>3 * limit) return 0;
        long long ans = com(n + 2);
        if (n > limit) ans -= 3 * com(n - limit + 1);
        if (n - 2 >= 2 * limit) ans += 3 * com(n - 2 * limit);
        return ans;
    }
};
