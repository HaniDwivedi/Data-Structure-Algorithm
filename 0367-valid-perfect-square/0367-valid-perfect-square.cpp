class Solution {
public:
    bool isPerfectSquare(int num) {
        // Handle edge cases
        if (num < 0) return false;
        if (num == 0 || num == 1) return true;

        unordered_map<int, int> mp;
        
        // Find prime factorization frequencies
        // Optimization: stop loop when i * i > num
        for (long long i = 2; i * i <= num; i++) {
            while (num % i == 0) {
                mp[i]++;
                num /= i;
            }
        }
        // If remaining num > 1, it is a prime factor itself
        if (num > 1) {
            mp[num]++;
        }

        // Verify if all exponents are even numbers
        for (auto it : mp) {
            if (it.second % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};
