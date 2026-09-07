class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        int result = -1;

        for (int num : nums) {
            if (num % 2 == 0) {
                freq[num]++;
                if (freq[num] > maxFreq) {
                    maxFreq = freq[num];
                    result = num;
                } else if (freq[num] == maxFreq) {
                    result = min(result, num);
                }
            }
        }
        return result;
    }
};