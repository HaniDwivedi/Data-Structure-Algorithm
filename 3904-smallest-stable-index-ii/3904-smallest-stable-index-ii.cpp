class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
    
int maxi=INT_MIN;
        int mini=INT_MAX;
        int n=nums.size();
   vector<int> s(n);   
if (n == 0) return -1;
s[n-1] = nums[n-1];

        for(int i=n-2;i>=0;i--){
            s[i]=min(nums[i],s[i+1]);
        }
        
       for(int i=0;i<nums.size();i++){
          maxi=max(nums[i],maxi);
           mini=s[i];
           
           if((maxi-mini)<=k)return i;
         
       
       }
        return -1;


    }
};