class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
     char ans;int m =INT_MAX;bool isfound=0;
     for(char c:letters){
        int a= target-'a';
        int b= c-'a';
        int t=b-a;
        if(t>0&&t<m){m=abs(a-b);isfound=1;
        ans=c;}
     }  
      if(isfound==1)return ans;
      else return letters[0];
    }
};