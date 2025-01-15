class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int k = __builtin_popcount(num2);
        if (__builtin_popcount(num1) == k) return num1;

        int x = 0;
        for (int i = 31; i >= 0; --i) {
            if ((num1 >> i) & 1) {
                if (k > 0) {
                    x |= (1 << i);
                    k--;
                }
            }
        }

        for (int i = 0; i < 32 && k > 0; ++i) {
            if (!((x >> i) & 1)) {
                x |= (1 << i);
                k--;
            }
        }

        return x;
    }
};