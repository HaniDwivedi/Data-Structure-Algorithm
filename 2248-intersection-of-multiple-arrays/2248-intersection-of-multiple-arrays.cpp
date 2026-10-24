class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int m = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < m; i++) {
            // 1. Sort the row first so unique() can remove consecutive duplicates
            sort(nums[i].begin(), nums[i].end());
            
            // 2. Remove duplicates within this specific row
            auto it_end = unique(nums[i].begin(), nums[i].end());
            
            // 3. Loop up to the new unique end iterator
            int n = distance(nums[i].begin(), it_end);
            for (int j = 0; j < n; j++) {
                mp[nums[i][j]]++;
            } 
        }

        vector<int> ans;

        // 4. Check which elements appeared in all 'm' rows
        for (auto it : mp) {
            if (it.second == m) {
                ans.push_back(it.first); // fixed the typo: psuh_back -> push_back
            }
        }

        // 5. The problem requires the result sorted in ascending order
        sort(ans.begin(), ans.end());

        return ans;
    }
};