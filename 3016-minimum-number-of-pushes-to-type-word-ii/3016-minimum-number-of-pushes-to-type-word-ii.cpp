#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        // Frequency array of size 26 for alphabet letters
        vector<int> freq(26, 0);
        
        // Count frequencies in O(N) time
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        
        // Sorting only 26 elements takes O(1) constant time, not O(N log N)
        sort(freq.begin(), freq.end(), greater<int>());
        
        int total_pushes = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            
            // Multiplier changes every 8 elements (1st-8th: multiplier 1, 9th-16th: multiplier 2, etc.)
            total_pushes += freq[i] * (i / 8 + 1);
        }
        
        return total_pushes;
    }
};