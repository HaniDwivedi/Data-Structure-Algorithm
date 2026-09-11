#include <vector>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        // Step 1: Count the frequency of each digit available in the pool
        vector<int> originalCount(10, 0);
        for (int d : digits) {
            originalCount[d]++;
        }
        
        int cnt = 0;
        
        // Step 2: Loop through all valid 3-digit even numbers
        for (int i = 100; i < 1000; i++) {
            // Check if even
            if (i % 2 != 0) continue; 
            
            // Extract individual digits
            int hundreds = i / 100;
            int tens = (i / 10) % 10;
            int ones = i % 10;
            
            // Step 3: Count what digits are required for the number `i`
            vector<int> requiredCount(10, 0);
            requiredCount[hundreds]++;
            requiredCount[tens]++;
            requiredCount[ones]++;
            
            // Step 4: Verify if we have enough copies of each digit
            bool canForm = true;
            for (int d = 0; d < 10; d++) {
                if (requiredCount[d] > originalCount[d]) {
                    canForm = false;
                    break;
                }
            }
            
            if (canForm) {
                cnt++;
            }
        }
        
        return cnt;
    }
};
