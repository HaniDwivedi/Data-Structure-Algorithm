class Solution {
public:
    int reverseDegree(string s) {
        int sum =0; int p =1;
        for(char c :s){
            int n =c-'a';
           int t=26-n;
            sum+=p*t;
            p++;
        }
        return sum ; 
    }
};