#define ll long long

class Solution {
    // Converts a vector of digits into the corresponding number
    ll vectorToNumber(vector<int>& num) {
        ll ans = 0;
        for (int digit : num) {
            ans = ans * 10 + digit;
        }
        return ans;
    }

    // Computes factorial of a number
    ll fact(int n){
        ll ans = 1;
        for(int i = 2; i <= n; i++) ans *= i;
        return ans;
    }

    // Calculates total number of permutations based on digit frequencies
    ll Total_Permutations(map<int, int> &freq, int n) {
        ll totalPermutations = fact(n);

        // Divide by factorial of each digit frequency to avoid overcounting
        for (auto i : freq) {
            totalPermutations /= fact(i.second);
        }
        return totalPermutations;
    }

    // Calculates the number of permutations that start with 0 (invalid)
    ll PermutationsStartingWithZero(map<int, int> freq, int n) {
        // If no zeros are present, return 0
        if (freq.find(0) == freq.end() || freq[0] == 0) {
            return 0;
        }

        // Fix one zero as the first digit (invalid), reduce its count
        freq[0]--;
        ll permutationsWithZero = fact(n - 1);

        // Divide by factorials of updated frequencies
        for (auto& i : freq) {
            permutationsWithZero /= fact(i.second);
        }
        return permutationsWithZero;
    }

    // Calculates valid permutations (not starting with 0)
    ll calc(map<int,int> &freq, int n){
        ll total = Total_Permutations(freq, n);
        ll withZero = PermutationsStartingWithZero(freq, n);
        return total - withZero;
    }

public:
    ll ans = 0;  // Final count of good integers
    set<map<int,int>> vis;  // Set to avoid duplicate digit frequency maps

    // Recursively generates all palindromic numbers of length n
    void generatePalindrome(vector<int>& num, int left, int right, int k, int n) {
        // Base case: finished building the palindrome
        if (left > right) {
            ll pali = vectorToNumber(num);

            // Check if the palindrome is divisible by k
            if (pali % k == 0) {
                map<int,int> m;

                // Build frequency map of digits
                while(pali) {
                    m[pali % 10]++;
                    pali /= 10;
                }

                // If this frequency map hasn't been seen before
                if(vis.find(m) == vis.end()) {
                    ans += calc(m, n);  // Add valid permutations to answer
                    vis.insert(m);      // Mark this frequency as seen
                }
            }
            return;
        }

        // Try all digits from 0 to 9 in the current positions
        for (int digit = (left == 0) ? 1 : 0; digit <= 9; ++digit) {
            num[left] = num[right] = digit;  // Mirror the digit at both ends
            generatePalindrome(num, left + 1, right - 1, k, n);
        }
    }

    // Main function to start generating and counting good integers
    ll countGoodIntegers(int n, int k) {
        vector<int> num(n);  // Placeholder for current palindrome
        generatePalindrome(num, 0, n - 1, k, n);
        return ans;
    }
};
