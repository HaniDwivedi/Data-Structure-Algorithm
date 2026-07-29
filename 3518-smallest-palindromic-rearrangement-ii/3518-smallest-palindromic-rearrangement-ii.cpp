#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function to calculate multinomial coefficient L! / (f0! * f1! * ... * f25!)
    // Returns a value capped at k limit to prevent integer overflow.
    long long countPermutations(const vector<int>& freq, long long limit) {
        int total = 0;
        for (int f : freq) total += f;

        // Calculate combination total! / (f0! f1! ...) using Pascal/Combinations
        // We use double or capped long long to prevent overflow
        long long ways = 1;
        int current_total = total;

        for (int f : freq) {
            if (f <= 0) continue;
            // Calculate C(current_total, f)
            for (int i = 1; i <= f; ++i) {
                ways = ways * (current_total - f + i) / i;
                if (ways > limit) return limit + 1; // Cap early to prevent overflow
            }
            current_total -= f;
        }

        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> count(26, 0);

        // Step 1: Count character frequencies
        for (char c : s) {
            count[c - 'a']++;
        }

        // Step 2: Extract middle odd character if n is odd, divide rest by 2
        char oddChar = '\0';
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                oddChar = 'a' + i;
            }
            count[i] /= 2;
        }

        int m = n / 2;
        
        // Total possible palindromic permutations
        long long totalPerms = countPermutations(count, k);
        if (totalPerms < k) {
            return ""; // Not enough distinct permutations
        }

        string leftHalf = "";
        long long currentK = k;

        // Step 3: Build left half character by character
        for (int i = 0; i < m; i++) {
            for (int c = 0; c < 26; c++) {
                if (count[c] == 0) continue;

                // Temporarily place character c
                count[c]--;

                // Count how many ways remain with current choice
                long long numWays = countPermutations(count, currentK);

                if (currentK <= numWays) {
                    leftHalf += (char)('a' + c);
                    break; // Picked this character, move to next index
                } else {
                    currentK -= numWays;
                    count[c]++; // Backtrack and try next character
                }
            }
        }

        // Step 4: Reconstruct full palindrome
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        if (n % 2 != 0) {
            return leftHalf + oddChar + rightHalf;
        } else {
            return leftHalf + rightHalf;
        }
    }
};