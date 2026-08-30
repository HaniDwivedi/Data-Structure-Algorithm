class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = 0;
        int maxi = 0;
        int n = nums.size();
        
       
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[maxi]) maxi = i;
            if (nums[i] < nums[mini]) mini = i;
        }
        
        int left = min(mini, maxi);
        int right = max(mini, maxi);
        
      
        int removeFromFrontOnly = right + 1;
        
     
        int removeFromBackOnly = n - left;
     
        int removeFromBothSides = (left + 1) + (n - right);
        
      
        return min({removeFromFrontOnly, removeFromBackOnly, removeFromBothSides});
    }
};
