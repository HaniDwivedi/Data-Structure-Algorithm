class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> a; 
  
        for (int n : nums) {
            if (n > 0 && n % k == 0) {
                a.push_back(n);
            }
        }

        sort(a.begin(), a.end());

        a.erase(unique(a.begin(), a.end()), a.end());

        int p = k;
        for (int n : a) {
            if (n != p) return p;
            p += k;              
        }

        return p; 
    }
};