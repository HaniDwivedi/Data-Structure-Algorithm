class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        
        int idx = 0;
        int current = nums[0];
        
        while (idx < nums.size()) {
            if (nums[idx] == current) {
                idx++;
            } else {
                ans.push_back(current); 
            }
            current++;
        }
        
        return ans;
    }
};