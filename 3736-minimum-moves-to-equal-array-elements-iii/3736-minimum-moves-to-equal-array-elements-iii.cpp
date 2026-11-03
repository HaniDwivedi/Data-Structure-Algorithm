class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_ele=INT_MIN;
for(int n : nums){
            max_ele=max(max_ele,n);
        }


        int ans=0;
        for(int n : nums){
            ans+=max_ele-n;
        }return ans;
    }
};