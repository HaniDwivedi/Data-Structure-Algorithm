class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    
        while (stones.size() > 1) {
           
            sort(stones.begin(), stones.end());
            
            int n = stones.size();
            int y = stones[n - 1]; // Heaviest
            int x = stones[n - 2]; // Second heaviest
            
            // Remove the two heaviest stones
            stones.pop_back();
            stones.pop_back();
            
            // If they aren't equal, push the remaining stone back
            if (x != y) {
                stones.push_back(y - x);
            }
        }
        
        return stones.empty() ? 0 : stones[0];
    }
};