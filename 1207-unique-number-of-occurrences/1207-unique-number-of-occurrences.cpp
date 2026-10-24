class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int,int>mp;
         for(int n : arr)mp[n]++;
set<int>s1;
         for(auto  it :  mp ){
           if(s1.find(it.second)!=s1.end())  return false;       
            s1.insert(it.second);
         }     

         return true;
    }
};