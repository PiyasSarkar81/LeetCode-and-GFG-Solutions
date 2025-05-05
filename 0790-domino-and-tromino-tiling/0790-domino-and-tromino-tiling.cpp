class Solution {
    int mod = 1e9+7;
public:
    int numTilings(int n) {
        if (n<3) return n;
        vector<long> domino(n+1,0), tromino(n+1,0);

        domino[1] = 1, domino[2] = 2, tromino[1] = 1, tromino[2] = 2;

        for(int i=3;i<=n;i++){
            domino[i] = (domino[i-1] + domino[i-2] + 2*tromino[i-2]) % mod;
            tromino[i] = (tromino[i-1] + domino[i-1]) % mod;
        }

        return domino[n];
    }
};