class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                cnt++;
            }
            if (nums[i] != nums[i - 1]) {
                cnt = 0;
            }
            if (cnt >=2) {
                nums.erase(nums.begin() + i);
                i--;cnt--;
            }
        }
        int a = nums.size();
        return a;
    }
};