#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            
            // Check karein ki complement map mein pehle se present hai ya nahi
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            
            // Current number aur uska index map mein store karein
            numMap[nums[i]] = i;
        }
        
        return {}; // No solution case (waise problem ke mutabiq hamesha ek solution hoga)
    }
};