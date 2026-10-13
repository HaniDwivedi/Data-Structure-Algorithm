class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
   int n = nums.size();
        vector<long long> squares(n);

        for(int i = 0; i < n; i++) {
            squares[i] = (long long)nums[i] * nums[i];
        }
        sort(squares.begin(), squares.end());
long long maxScore = 0;
for(int i = 0; i < n; i++) {
            if (i < n / 2) {
             
                maxScore -= squares[i];
            } else {
              
                maxScore += squares[i];
            }
        }return maxScore;
        
    }
};