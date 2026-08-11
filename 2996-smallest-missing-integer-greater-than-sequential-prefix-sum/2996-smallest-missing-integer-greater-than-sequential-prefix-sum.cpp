class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find the sum of the longest consecutive prefix
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break;
            }
        }

        // Find the smallest integer >= sum that is not in nums
        int ans = sum;

        while (true) {
            bool found = false;

            for (int x : nums) {
                if (x == ans) {
                    found = true;
                    break;
                }
            }

            if (!found)
                return ans;

            ans++;
        }
    }
};